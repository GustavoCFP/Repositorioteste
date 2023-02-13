#pragma config(Sensor, S1,     ,               sensorTouch)
#pragma config(Sensor, S2,     ,               sensorTouch)
#pragma config(Sensor, S3,     ,               sensorTouch)
#pragma config(Sensor, S4,     ,               sensorTouch)
#pragma config(Motor,  motorA,          Motor1,        tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorB,          Motor2,        tmotorNXT, PIDControl, reversed, encoder)
#pragma config(Motor,  motorC,          motor3,        tmotorNXT, PIDControl, reversed, encoder)

#include "RinobotLib.h"

void cair(int tempo_caida_frente, int tempo_caida_tras)
{
	VelocidadeEscolha = ESTRATEGIA_PADRAO;
	StatusMotor = FRENTE;
	AnguloMotor = 0;
	SelecionarTipoMovimentacao();
	wait1Msec(tempo_caida_frente);
	StatusMotor = PARA_TRAS;
	AnguloMotor = 180;
	SelecionarTipoMovimentacao();
	wait1Msec(tempo_caida_tras);
}

task main()
{

}
