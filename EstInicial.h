/********************************************
*********************************************
**** Essa biblioteca tem como objetivo *****
**** organizar todas as estrategias criadas**
**** e gerenciar quais serao utiizadas. *****
*********************************************
*********************************************/

#define DISPLAY -1
#define NADA 0
#define GIRA_GRAUS 1
#define OLEEE 2
#define OLEZINHO 3
#define CURVA_TRAS 4
#define CURVA 5
#define _90_CURVA 6
#define _70_CURVA 7
#define ANDA_GIRA 8
#define RE_GIRA 9
#define DIAGONAL 10
#define _45_RE 11
#define REZINHA 12
#define DESEMPATE 13

static bool EstInicialCompleta = false;
static int lado;
static bool mov_atual_completa = 0;
const int MOV1 = 0, MOV2 = 1, MOV3 = 2;
static int mov_atual = MOV1;

/************************************************************
Essa funcao tem como objetivo varrer o vetor *estrategia e
configurar qual sera o nome a ser exibido na tela
*************************************************************/
void ConfigurarMovimentacaoInicial(int *estrategia)
{
	for(int i = 0; i < 9; i++)
	{
		switch(estrategia[i])
		{
		case DISPLAY:
			Menus[MOV_INICIAL][i] = "Mov. Inicial";
			break;
		case NADA:
			Menus[MOV_INICIAL][i] = "Nada";
			break;
		case GIRA_GRAUS:
			Menus[MOV_INICIAL][i] = "GiraGraus";
			break;
		case OLEEE:
			Menus[MOV_INICIAL][i] = "Oleee";
			break;
		case OLEZINHO:
			Menus[MOV_INICIAL][i] = "Olezinho";
			break;
		case CURVA_TRAS:
			Menus[MOV_INICIAL][i] = "CurvaTras";
			break;
		case CURVA:
			Menus[MOV_INICIAL][i] = "Curva";
			break;
		case _90_CURVA:
			Menus[MOV_INICIAL][i] = "_90Curva";
			break;
		case _70_CURVA:
			Menus[MOV_INICIAL][i] = "_70Curva";
			break;
		case ANDA_GIRA:
			Menus[MOV_INICIAL][i] = "andaGira";
			break;
		case RE_GIRA:
			Menus[MOV_INICIAL][i] = "reGira";
			break;
		case DIAGONAL:
			Menus[MOV_INICIAL][i] = "Diagonal";
			break;
		case _45_RE:
			Menus[MOV_INICIAL][i] = "_45re";
			break;
		case REZINHA:
			Menus[MOV_INICIAL][i] = "rezinha";
			break;
		case DESEMPATE:
			Menus[MOV_INICIAL][i] = "Desempate";
			break;
	}
}
}

/*************************************
Funcao usada para definir quantos
graus o robo ira girar
***********************************/
void definirAngulo()
{
	nxtDisplayCenteredBigTextLine(0, "#GoRino");
	nxtDisplayCenteredTextLine(3, "Angulo:");
	nxtDisplayCenteredBigTextLine(5,"   %d    ",Graus);
	while(true)
	{
		if(nNxtButtonPressed != -1){
			if(nNxtButtonPressed == BotaoDireito)
			{
				Graus = Graus + 15;
			}
			if(nNxtButtonPressed == BotaoEsquerdo)
			{
				if(Graus <= 0){}
				else
				{
					Graus = Graus - 15;
				}
			}
			if(nNxtButtonPressed == BotaoLaranja)
			{
				while(nNxtButtonPressed != -1){}
				eraseDisplay();
				break;
			}
			nxtDisplayCenteredBigTextLine(0, "#GoRino");
			nxtDisplayCenteredTextLine(3, "Angulo:");
			nxtDisplayCenteredBigTextLine(5,"   %d    ",Graus);
			while(nNxtButtonPressed != -1){}
		}
	}
	//return Graus;
}

/***********************************
Estrategia de girar no proprio eixo
************************************/
void EstrategiaGiraGraus()
{
	if(ladoInicial != -1)
	{
		lado = ladoInicial;
	}
	else
	{
		lado = UltimoLado;
	}
	EstInicialCompleta = giraXGraus(lado, Graus, 1);
}

/*************************************
Estrategia na qual o robo gira 55°,
anda 30 cm e gira 80° na direcao
oposta do ladoInicial
***********************************/
void EstrategiaOleee()
{
	if(ladoInicial != -1)
	{
		lado = ladoInicial;
	}
	else
	{
		lado = UltimoLado;
	}
	switch(mov_atual)
	{
	case MOV1:
		mov_atual_completa = giraXGraus(lado, 55, 1);
		break;
	case MOV2:
		mov_atual_completa = AndaXcm(30,1,1);
		break;
	case MOV3:
		mov_atual_completa = giraXGraus(!lado, 80, 1);
		break;
	default:
		EstInicialCompleta = true;
		break;
	}
	if(mov_atual_completa)
	{
		mov_atual++;
	}
}

/*************************************
Estrategia na qual o robo gira 15°,
anda 10 cm e gira 30° na direcao
oposta da inicial
***********************************/
void EstrategiaOlezinho()
{
	if(ladoInicial != -1)
	{
		lado = ladoInicial;
	}
	else
	{
		lado = UltimoLado;
	}
	switch(mov_atual)
	{
	case MOV1:
		mov_atual_completa = giraXGraus(lado, 15, 1);
		break;
	case MOV2:
		mov_atual_completa = AndaXcm(10,1,1);
		break;
	case MOV3:
		mov_atual_completa = giraXGraus(!lado, 30, 1);
		break;
	default:
		EstInicialCompleta = true;
		break;
	}
	if(mov_atual_completa)
	{
		mov_atual++;
	}
}

/**********************************************
Estrategia na qual o robo faz uma curva
de acordo com os parametros setados
**********************************************/
void EstrategiaCurva()
{
	if(ladoInicial != -1)
	{
		lado = ladoInicial;
	}
	else
	{
		lado = UltimoLado;
	}
	EstInicialCompleta = fazerCurva(lado, 36.5 - 2.5, 229.3/4 -10, 1, 1);
}

/*********************************************
Estrategia na qual o robo gira 90° e
depois realiza uma curva na direcao oposta
de acordo com os parametros setados
*********************************************/
void Estrategia90Curva()
{
	if(ladoInicial != -1)
	{
		lado = ladoInicial;
	}
	else
	{
		lado = UltimoLado;
	}
	switch(mov_atual)
	{
	case MOV1:
		mov_atual_completa = giraXGraus(lado, 90, 1);
		break;
	case MOV2:
		mov_atual_completa = fazerCurva(!lado, 38.5-2, 229.3/4 -10, 1, 1);
		break;
	default:
		EstInicialCompleta = true;
		break;
	}
	if(mov_atual_completa)
	{
		mov_atual++;
	}
}

/***********************************************
Estrategia na qual o robo faz uma curva
para tras de acordo com os parametros setados
***********************************************/
void EstrategiaCurvaTras()
{
	if(ladoInicial != -1)
	{
		lado = ladoInicial;
	}
	else
	{
		lado = UltimoLado;
	}
	EstInicialCompleta = fazerCurva(lado, 20, PI/4*25, 0, 1);
}

/************************************************
Estrategia na qual o robo anda 20 cm para frente
e gira 90°para o lado selecionado
************************************************/
void EstrategiaDiagonal()
{
	if(ladoInicial != -1)
	{
		lado = ladoInicial;
	}
	else
	{
		lado = UltimoLado;
	}
	switch(mov_atual)
	{
	case MOV1:
		mov_atual_completa = AndaXcm(20,1,1);
		break;
	case MOV2:
		mov_atual_completa = giraXGraus(lado, 90, 1);
		break;
	case MOV3:
		mov_atual_completa = esperarAdversario();
		break;
	default:
		EstInicialCompleta = true;
		break;
	}
	if(mov_atual_completa)
	{
		mov_atual++;
	}
}

/*********************************************
Estrategia na qual o robo gira 70° e
depois realiza uma curva na direcao oposta
do ladoInicial selecionado
*********************************************/
void Estrategia70Curva()
{
	int raio = 25;

	if(ladoInicial != -1)
	{
		lado = ladoInicial;
	}
	else
	{
		lado = UltimoLado;
	}
	switch(mov_atual)
	{
	case MOV1:
		mov_atual_completa = giraXGraus(lado, 70, 1);
		break;
	case MOV2:
		mov_atual_completa = fazerCurva(!lado, raio, raio * PI / 4 * 1.4, 1, 1);
		break;
	case MOV3:
		mov_atual_completa = esperarAdversario();
		break;
	default:
		EstInicialCompleta = true;
		break;
	}
	if(mov_atual_completa)
	{
		mov_atual++;
	}
}

/*********************************************
Estrategia na qual o robo gira 45°
e depois anda 20 cm para tras
*********************************************/
void Estrategia45re()
{
	if(ladoInicial != -1)
	{
		lado = ladoInicial;
	}
	else
	{
		lado = UltimoLado;
	}
	switch(mov_atual)
	{
	case MOV1:
		mov_atual_completa = giraXGraus(lado, 45, 1);
		break;
	case MOV2:
		mov_atual_completa = AndaXcm(20,0,1);
		break;
	case MOV3:
		mov_atual_completa = esperarAdversario();
		break;
	default:
		EstInicialCompleta = true;
		break;
	}
	if(mov_atual_completa)
	{
		mov_atual++;
	}
}

/*********************************************
Estrategia na qual o robo anda 18 cm para tras
e gira 60° para o lado selecionado
*********************************************/
void EstrategiaReGira()
{
	UltimoLado = !ladoInicial;

	if(ladoInicial != -1)
	{
		lado = ladoInicial;
	}
	else
	{
		lado = UltimoLado;
	}
	switch(mov_atual)
	{
	case MOV1:
		mov_atual_completa = AndaXcm(18,0,1);
		break;
	case MOV2:
		mov_atual_completa = giraXGraus(lado, 60, 1);
		break;
	case MOV3:
		mov_atual_completa = esperarAdversario();
		break;
	default:
		EstInicialCompleta = true;
		break;
	}
	if(mov_atual_completa)
	{
		mov_atual++;
	}
}

/*********************************************
Estrategia na qual o robo anda 18 cm para frente
e gira 60° para o lado selecionado
*********************************************/
void EstrategiaAndaGira()
{
	if(ladoInicial != -1)
	{
		lado = ladoInicial;
	}
	else
	{
		lado = UltimoLado;
	}
	switch(mov_atual)
	{
	case MOV1:
		mov_atual_completa = AndaXcm(18,1,1);
		break;
	case MOV2:
		mov_atual_completa = giraXGraus(lado, 90, 1);
		break;
	case MOV3:
		mov_atual_completa = esperarAdversario();
		break;
	default:
		EstInicialCompleta = true;
		break;
	}
	if(mov_atual_completa)
	{
		mov_atual++;
	}
}

/*********************************************
Estrategia na qual o robo anda 10 cm para tras
*********************************************/
void EstrategiaRezinha()
{
	UltimoLado = !ladoInicial;
	if(ladoInicial != -1)
	{
		EstInicialCompleta = AndaXcm(10,0,1);
	}
	else
	{
		EstInicialCompleta = AndaXcm(10,0,1);
	}
}

/*********************************************
Estrategia para desempate(robo anda de costas)
*********************************************/
void EstrategiaDesempate()
{
	AndaXcm(30,0,1);
  //EstInicialCompleta = AndaXcm(30,0,1);
}

/*********************************************
Essa funcao tem o objetivo de inicializar
a estrategia selecionada no display
*********************************************/
bool ExecutarEstrategiaInicial()
{
	if(movimentacaoInicial == NADA)
	{
		EstInicialCompleta = true;
		//StartTask(EstrategiaPadrao);
	}
	else if(movimentacaoInicial == GIRA_GRAUS)
	{
		EstrategiaGiraGraus();
	}
	else if(movimentacaoInicial == OLEEE)
	{
		EstrategiaOleee();
	}
	else if(movimentacaoInicial == OLEZINHO)
	{
		EstrategiaOlezinho();
	}
	else if(movimentacaoInicial == CURVA_TRAS)
	{
		EstrategiaCurvaTras();
	}
	else if(movimentacaoInicial == CURVA)
	{
		EstrategiaCurva();
	}
	else if(movimentacaoInicial == _90_CURVA)
	{
		Estrategia90Curva();
	}
	else if(movimentacaoInicial == _70_CURVA)
	{
		Estrategia70Curva();
	}
	else if(movimentacaoInicial == RE_GIRA)
	{
		EstrategiaReGira();
	}
	else if(movimentacaoInicial == ANDA_GIRA)
	{
		EstrategiaAndaGira();
	}
	else if(movimentacaoInicial == DIAGONAL)
	{
		EstrategiaDiagonal();
	}
	else if(movimentacaoInicial == _45_RE)
	{
		Estrategia45re();
	}
	else if(movimentacaoInicial == REZINHA)
	{
		EstrategiaRezinha();
	}
	else if(movimentacaoInicial == DESEMPATE)
	{
		EstrategiaDesempate();
	}
	return !EstInicialCompleta;
}
