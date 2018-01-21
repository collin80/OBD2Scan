
#include <due_can.h>
#include <iso-tp.h>
#include "obd2_codes.h"

#ifndef  _VARIANT_MACCHINA_M2_
  #error "You don't seem to be compiling for the M2! Aborting!"
#endif

IsoTp isotp0(&Can0);
IsoTp isotp1(&Can1);

#define ECU_STARTID   0x7E0
#define ECU_ENDID     0x7E7
#define REPLY_OFFSET  8 //might be 0x10 or even 0x20 on your car

struct Message_t TxMsg, RxMsg;

void canSetupSpeed(CAN_COMMON *bus, uint32_t defaultSpeed)
{
	bus->enable();
  uint32_t canSpeed = bus->beginAutoSpeed(); //try to figure out the proper speed automatically.
  if (canSpeed > 0)
  {
    SerialUSB.print("Autobaud detected speed is ");
    SerialUSB.println(canSpeed);  
  }
  else
  {
    bus->begin(defaultSpeed);
    SerialUSB.print("Auto speed detect failed. Using ");
    SerialUSB.println(defaultSpeed);
  }  
  SerialUSB.println();
}

void displayBitfield(uint32_t bits)
{
  for (int i = 0; i < 4; i++)
  {
    for (int j = 7; j > -1; j--)
    {
      if (bits & (1ul << ((i*8) + j))) SerialUSB.write('1');
      else SerialUSB.write('0');
    }
  }
}

void queryECU(uint32_t id, IsoTp *iso)
{
  SerialUSB.print("Querying ECU at 0x");
  SerialUSB.println(id, HEX);

  TxMsg.len = 2;
  TxMsg.tx_id = id;
  TxMsg.rx_id = id + REPLY_OFFSET;
  TxMsg.Buffer[0] = OBDII_VEHICLE_INFO;
  TxMsg.Buffer[1] = VI_VIN;  
  iso->send(&TxMsg);
  SerialUSB.print("Reported VIN#: ");
  RxMsg.tx_id = id;
  RxMsg.rx_id = id + REPLY_OFFSET;
  iso->receive(&RxMsg);
  
  if (RxMsg.tp_state == ISOTP_FINISHED)
  {
    for (int i = 2; i < RxMsg.len; i++)  //the first two bytes are the mode and PID so skip those here.
    {
      if (RxMsg.Buffer[i] != 0) SerialUSB.write(RxMsg.Buffer[i]);
    }
    SerialUSB.println();
  }
  else
  {
    SerialUSB.println("ERR!");
  }
  RxMsg.tp_state = ISOTP_IDLE;

  TxMsg.Buffer[0] = OBDII_VEHICLE_INFO;
  TxMsg.Buffer[1] = VI_ECU_NAME;
  iso->send(&TxMsg);
  SerialUSB.print("Reported ECU Name: ");
  iso->receive(&RxMsg);
  if (RxMsg.tp_state == ISOTP_FINISHED)
  {
    for (int i = 2; i < RxMsg.len; i++)
    {
      if (RxMsg.Buffer[i] != 0) SerialUSB.write(RxMsg.Buffer[i]);
    }
    SerialUSB.println();
  }
  else
  {
    SerialUSB.println("ERR!");
  }
  RxMsg.tp_state = ISOTP_IDLE;

  for (int j = 0; j < 5; j++)
  {
    RxMsg.tp_state = ISOTP_IDLE;
    TxMsg.Buffer[0] = OBDII_SHOW_CURRENT;
    TxMsg.Buffer[1] = PID_SUPPORTED1 + (j * 0x20);
    iso->send(&TxMsg);
    SerialUSB.print("Supported PIDs ");
    SerialUSB.print(j * 32);
    SerialUSB.print("-");
    SerialUSB.print((j * 32) + 31);
    SerialUSB.print(": ");
    iso->receive(&RxMsg);
    if (RxMsg.tp_state == ISOTP_FINISHED)
    {
      uint32_t bits = RxMsg.Buffer[2] + (RxMsg.Buffer[3] * 256) + (RxMsg.Buffer[4] * 65536ul) + (RxMsg.Buffer[5] * 256ul * 65536ul);
      displayBitfield(bits);
      SerialUSB.println();
    }
    else
    {
      SerialUSB.println("ERR!");
    }
  }

  SerialUSB.println();
}

void setup()
{
  delay(4000);
  SerialUSB.begin(1000000);
  SerialUSB.println("OBDII Scanner for M2");
  SerialUSB.println("********************");
  SerialUSB.println();
  
  SerialUSB.print("CAN0:");
  canSetupSpeed(&Can0, 500000);
  SerialUSB.print("CAN1:");
  canSetupSpeed(&Can1, 250000);
  
  for (int filter = 0; filter < 3; filter++) {
      Can0.setRXFilter(filter, 0, 0, true);
      Can1.setRXFilter(filter, 0, 0, true);
  }  
  //standard
  for (int filter = 3; filter < 7; filter++) {
      Can0.setRXFilter(filter, 0, 0, false);
      Can1.setRXFilter(filter, 0, 0, false);
   }  

  TxMsg.Buffer=(uint8_t *)calloc(MAX_MSGBUF,sizeof(uint8_t));
  RxMsg.Buffer=(uint8_t *)calloc(MAX_MSGBUF,sizeof(uint8_t));

  /*
  The OBDII standard says that ECUs should respond to ids in the range 0x7E0 to 0x7E7. They should
  respond 0x08 higher than their ID so 0x7E0 responds with ID 0x7E8. Some cars don't follow this standard
  very closely and thus use addresses outside this range and return offsets other than 0x8. 0x10 is common too.
  Modify REPLY_OFFSET to change the offset. Modify ECU_STARTID and ECU_ENDID to change the range.
  */

  SerialUSB.println("----==== CAN0 ECUS ====----");
  uint32_t ecuID;
  for (ecuID = ECU_STARTID; ecuID <= ECU_ENDID; ecuID++)
  {
    queryECU(ecuID, &isotp0);
  }

  SerialUSB.println("----==== CAN1 ECUS ====----");
  for (ecuID = ECU_STARTID; ecuID <= ECU_ENDID; ecuID++)
  {
    queryECU(ecuID, &isotp1);
  }

}

void loop()
{ 
}

