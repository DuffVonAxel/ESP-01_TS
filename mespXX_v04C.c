/*
 * File:   mespXX_v04C.c
 * Author: Fred_Dell
 *
 * Created on 23 de Agosto de 2021, 17:15
 */
// CONFIG1L
#pragma config PLLDIV = 5       // PLL Prescaler Selection bits (Divide by 5 (20 MHz oscillator input))
#pragma config CPUDIV = OSC1_PLL2// System Clock Postscaler Selection bits ([Primary Oscillator Src: /1][96 MHz PLL Src: /2])
#pragma config USBDIV = 1       // USB Clock Selection bit (used in Full-Speed USB mode only; UCFG:FSEN = 1) (USB clock source comes directly from the primary oscillator block with no postscale)

// CONFIG1H
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator (HS))
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRT = OFF       // Power-up Timer Enable bit (PWRT disabled)
#pragma config BOR = OFF        // Brown-out Reset Enable bits (Brown-out Reset disabled in hardware and software)
#pragma config BORV = 3         // Brown-out Reset Voltage bits (Minimum setting 2.05V)
#pragma config VREGEN = OFF     // USB Voltage Regulator Enable bit (USB voltage regulator disabled)

// CONFIG2H
#pragma config WDT = OFF        // Watchdog Timer Enable bit (WDT disabled (control is placed on the SWDTEN bit))
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = OFF     // CCP2 MUX bit (CCP2 input/output is multiplexed with RB3)
#pragma config PBADEN = OFF     // PORTB A/D Enable bit (PORTB<4:0> pins are configured as digital I/O on Reset)
#pragma config LPT1OSC = OFF    // Low-Power Timer 1 Oscillator Enable bit (Timer1 configured for higher power operation)
#pragma config MCLRE = OFF       // MCLR Pin Enable bit (MCLR pin enabled; RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = OFF     // Stack Full/Underflow Reset Enable bit (Stack full/underflow will not cause Reset)
#pragma config LVP = OFF        // Single-Supply ICSP Enable bit (Single-Supply ICSP disabled)
#pragma config ICPRT = OFF      // Dedicated In-Circuit Debug/Programming Port (ICPORT) Enable bit (ICPORT disabled)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection bit (Block 0 (000800-001FFFh) is not code-protected)
#pragma config CP1 = OFF        // Code Protection bit (Block 1 (002000-003FFFh) is not code-protected)
#pragma config CP2 = OFF        // Code Protection bit (Block 2 (004000-005FFFh) is not code-protected)
#pragma config CP3 = OFF        // Code Protection bit (Block 3 (006000-007FFFh) is not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) is not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM is not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection bit (Block 0 (000800-001FFFh) is not write-protected)
#pragma config WRT1 = OFF       // Write Protection bit (Block 1 (002000-003FFFh) is not write-protected)
#pragma config WRT2 = OFF       // Write Protection bit (Block 2 (004000-005FFFh) is not write-protected)
#pragma config WRT3 = OFF       // Write Protection bit (Block 3 (006000-007FFFh) is not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) are not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot block (000000-0007FFh) is not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM is not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection bit (Block 0 (000800-001FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection bit (Block 1 (002000-003FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection bit (Block 2 (004000-005FFFh) is not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection bit (Block 3 (006000-007FFFh) is not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot block (000000-0007FFh) is not protected from table reads executed in other blocks)

#define _XTAL_FREQ 20000000		// Determina cristal atual

/* Biblioteca V18 */
//#define _MPASSO_				// Habilita uso do Motor de passo.
#define _UART_					// Habilita uso da interface de comunicacao serial.
//#define _ADC_					// Habilita uso do Modulo ADC.
#define _LCD_					// Habilita uso do Display LCD.
//#define _TECLADO_				// Habilita uso do teclado matricial.
#define _DHT_					// Habilita uso do medidor de umidade/temperatura.
//#define _MCP_					// Habilita uso do GPIO Extender.
//#define _LCDI2C_				// Habilita uso do LCD acoplado ao PCF8574 (I2C).

/* Acesso ao Roteador */
//#define espApSsid			"IoT_Hub"				// SSID do roteador.
//#define espApPass			"SENAI127iot"			// Senha de acesso.
//#define espApSsid			"Atomation1"			// SSID do roteador.
//#define espApPass			"12345678"				// Senha de acesso.
//#define espApSsid			"Axel_2G"				// SSID do roteador.
//#define espApPass			"sn75123-5"				// Senha de acesso.
const unsigned char espApSsid[]  ={"IoT_AP"};								// SSID do roteador.
const unsigned char espApPass[]  ={"12345678"};									// Senha de acesso.

/* Servidor ESP */
//#define espSrvSsid			"ESP_WF"				// Ate 64 caracteres.
//#define espSrvPass			"0123456789"			// De 8 a 64 caracteres.
//#define espSrvCan			"5"						// Canal do servidor.
//#define espSrvEcn			"3"						// Metodo de criptografia 0=OPEN,2=WPA_PSK,3=WPA2_PSK,4=WPA_WPA2_PSK (WEP nao suportado).
//#define espSrvPorta			"333"					// Porta do servidor (padrao=333).
//#define espSrvLinkId		0						// Id da conexao. Recupera com  AT+CIPSTATUS.
const unsigned char espSrvSsid[] ={"ESP_WF"};									// Ate 64 caracteres.
const unsigned char espSrvPass[] ={"0123456789"};								// De 8 a 64 caracteres.
const unsigned char espSrvCan[]  ={"5"};										// Canal do servidor.
const unsigned char espSrvEcn[]  ={"3"};										// Metodo de criptografia 0=OPEN,2=WPA_PSK,3=WPA2_PSK,4=WPA_WPA2_PSK (WEP nao suportado).
const unsigned char espSrvPorta[]={"333"};										// Porta do servidor (padrao=333).

/* Servidor Web */
//#define webSrvIp			"192.168.0.190"			// Ip do servidor Web.
//#define webSrvCanal			"80"					// Canal de acesso ao Web Server. Padrao 80.
const unsigned char webSrvIp[]   ={"192.168.0.100"};							// Ip do servidor Web.
const unsigned char webSrvCanal[]={"80"};										// Canal de acesso ao Web Server. Padrao 80.

/* Servidor Banco de Dados */
//#define dbUser				"iotUserBd"				// Nome do usuario do BD.
//#define dbPass				"iotSENAI127"			// Senha de acesso ao BD.
//#define dbAcce				"/enviaBD.php"			// Pagina de acesso ao BD.
//#define dbTabela			"tabiot"				// Nome da tabela em uso no DB.
//#define dbCpId				"iotId"					// Campo Id.
//#define dbCpIn0				"iotin0"				// Campo Registro de entrada 0.
//#define dbCpIn1				"iotin1"				// Campo Registro de entrada 1.
const unsigned char dbUser[]     ={"iotUserBd"};								// Nome do usuario do BD.
const unsigned char dbPass[]     ={"iotSENAI127"};								// Senha de acesso ao BD.
const unsigned char dbAcce[]     ={"/enviaBD.php"};								// Pagina de acesso ao BD.
const unsigned char dbTabela[]   ={"tabiot"};									// Nome da tabela em uso no DB.
const unsigned char dbCpId[]     ={"iotId"};									// Campo Id.
const unsigned char dbCpIn0[]    ={"iotin0"};									// Campo Registro de entrada 0.
const unsigned char dbCpIn1[]    ={"iotin1"};									// Campo Registro de entrada 1.


/* Acesso ao ThingSpeak */
// https://api.thingspeak.com/update?api_key=P5PCN67Z5NBNC4D1&field1=82.1&field2=30.5
//#define tSpkDominio			"api.thingspeak.com"	// Endereco de acesso.
//#define tSpkEntrada			"/update?api_key="		// Como a API recebera o(s) dado(s).
//#define tSpkSaida			"/feeds/last.json"		// Como a API fornecera o(s) dado(s).
//#define tSpkPorta			"80"					// Porta de acesso.
//#define tSpkKeyWr			"P5PCN67Z5NBNC4D1"		// Chave da API de escrita.
//#define tSpkKeyRd			"689U0S0KM0QUCIKU"		// Chave da API de leitura.
//#define tSpkCanalId			"1476834"				// Identificacao do Canal de acesso.
//#define tSpkUser			"nome"					// Usuario de acesso.
//#define tSpkPass			"senha"					// Senha de acesso.
//#define tSpkPost			"POST /update HTTP/1.1"
const unsigned char tSpkDominio[]={"api.thingspeak.com"};						// Endereco de acesso.
const unsigned char tSpkPorta[]  ={"80"};										// Porta de acesso.
const unsigned char tSpkKeyWr[]  ={"P5PCN67Z5NBNC4D1"};							// Chave da API de escrita.
const unsigned char tSpkKeyRd[]  ={"689U0S0KM0QUCIKU"};							// Chave da API de leitura.
const unsigned char tSpkCanalId[]={"1476834"};									// Identificacao do Canal de acesso.

unsigned char campo1[5],campo2[5];
const unsigned char thSpkL1[]    ={"POST /update HTTP/1.1\r\n"};
const unsigned char thSpkL2[]    ={"Host: api.thingspeak.com\r\n"};
const unsigned char thSpkL3[]    ={"Connection: close\r\n"};
const unsigned char thSpkL4[]    ={"X-THINGSPEAKAPIKEY: "};
const unsigned char thSpkL5[]    ={"Content-Type: application/x-www-form-urlencoded\r\n"};
const unsigned char thSpkL6[]    ={"Content-Length: 23\r\n\r\n"};
const unsigned char thSpkL7[]    ={"field1="};
const unsigned char thSpkL8[]    ={"&field2="};

/* Acesso ao Thinger.io */
#define thIoUser			"DuffVonAxel"
#define thIoDevId			"ESP01_WF"
#define thIoDevCred			"Y_Szj#0PykOnL_E7"

/* Recepcao de dados */
#define espBufferSize		160	// era 160
#define espTimeOut			10000
volatile unsigned int Contador = 0; //, Ponteiro = 0;
unsigned char espBufferRx[espBufferSize];

/*  Transmissao de dados */
unsigned int contarTx=0;

/* Tempo */
unsigned char varTick=0;
unsigned char varSeg=0;
unsigned char varMin=0;
unsigned char varHor=0;

#include <xc.h>
#include "biblioteca_v18.h"

/* Constantes comuns */
const unsigned char atIni[]={"AT+"};
const unsigned char atCW0[]={"CW"};
const unsigned char atCIP[]={"CIP"};
const unsigned char atSys[]={"SYS"};
const unsigned char atUat[]={"UART"};
const unsigned char atCur[]={"_CUR="};
const unsigned char atDef[]={"_DEF="};
const unsigned char atAs1[]={"\""};
const unsigned char atAs2[]={"\",\""};
const unsigned char atFim[]={"\r\n"};

//void concatStrLCD(unsigned char *vlrStr1, unsigned char *vlrStr2, unsigned char *vlrStr3, unsigned char tamh)
//{
//	unsigned char varA, varB, varC;
//	varB=sizeString(vlrStr1);
//	for(varA=0;varA<varB;varA++)vlrStr3[varA]=vlrStr1[varA],varC++;
//	varB=sizeString(vlrStr2);
//	for(varA=varC;varA<varB;varA++)vlrStr3[varA]=vlrStr2[varA];
//}

void espClearBuffer(void)														// Limpa o buffer de recepcao do ESP.
{
	unsigned char cbTmp;														// Variavel local temporaria.
	for(cbTmp=0;cbTmp<espBufferSize;cbTmp++) espBufferRx[cbTmp]='\0';			// Limpa a variavel.
	Contador = 0;																// Reinicia a variavel 'Contador'.
}

unsigned char espRetOk(void)													// Retorna '1' se a resposta foi 'Ok' do ESP.
{
	unsigned char str090[]={"OK\r\n"};
	unsigned char varResp;														// Variavel local temporaria.
	varResp=procString(str090,espBufferRx);										// Verifica resposta.
	if(varResp<0xFF) varResp=1;													// Esta 'Ok'.
	else varResp=0;																// Nao esta 'Ok'.
	return(varResp);															// Retorna '1' se esta 'Ok', '0' nao esta 'Ok'.
}

/* Ok 100% */
unsigned char espOperacional(void)												// Testa se o ESP esta ativo.
{
	unsigned char str050[]={"AT"};
	unsigned char espVarTmp;													// Variavel local temporaria.
	espClearBuffer();															// Limpa o buffer de recepcao.
	// Comando: AT\r\n
	uartTXT(str050), uartTXT(atFim);											// Envia comando.
	__delay_ms(1500);															// Aguarda resposta. Trocar por Flag da INT?
	espVarTmp=espRetOk();														// Verifica resposta.
	return (espVarTmp);															// Retorna '1' se esta 'Ok', '0' nao esta 'Ok'.
}

/* Nao testado */
void espReset(void)																// Reset por software do ESP.
{
	unsigned char str040[]={"RST"};
	espClearBuffer();															// Limpa o buffer de recepcao.
	/* Aviso: Este comando demora para responder e 
	 * retorna caracteres invalidos com possiveis espurios. */
	// Comando: AT+RST\r\n
	uartTXT(atIni), uartTXT(str040), uartTXT(atFim);							// Envia o comando.
}

/* Nao testado */
void espEcho(unsigned char vlrEcho)												// Ativa (1)/Desativa (0) a funcao Echo do ESP.
{
	unsigned char str030[]={"ATE0"};
	unsigned char str031[]={"ATE1"};
	espClearBuffer();															// Limpa o buffer de recepcao.
	// Comando: ATE1\r\n ou ATE0\r\n
	if(vlrEcho==0) uartTXT(str030), uartTXT(atFim);								// Envia o comando deligando o Echo.
	if(vlrEcho==1) uartTXT(str031), uartTXT(atFim);								// Envia o comando ligando o Echo.
}

/* Nao testado */
void espInfo(unsigned char *vrsAt,unsigned char *vrsSdk,unsigned char *vrsBin)																// Recupera informacoes do ESP.
{
	unsigned char str120[]={"AT "};
	unsigned char str121[]={"SDK"};
	unsigned char str122[]={"Bin"};
	unsigned char str060[]={"GMR"};
	
	espClearBuffer();															// Limpa o buffer de recepcao.
	// Comando: AT+GMR\r\n
	uartTXT(atIni), uartTXT(str060), uartTXT(atFim);							// Envia o comando.
	__delay_ms(1500);
	retValorStr(espBufferRx,str122,vrsBin,8,12);
	retValorStr(espBufferRx,str120,vrsAt ,7,11);
	retValorStr(espBufferRx,str121,vrsSdk,5,12);
}

/* Nao testado */
void espModoWF(unsigned char vlrModoWF)											// Configura o WiFi. 1=Estacao, 2=Access Point, 3=Ambos.
{
	unsigned char str070[]={"MODE"};
	espClearBuffer();															// Limpa o buffer de recepcao.
	// Comando: AT+CWMODE=x. 1=Station, 2=SoftAP, 3=Sta+AP
	if(vlrModoWF<1) vlrModoWF=1;												// Validar valor minimo.
	if(vlrModoWF>3) vlrModoWF=3;												// Validar valor maximo.
	vlrModoWF += '0';															// Converte para ASCII.
	uartTXT(atIni), uartTXT(atCW0), uartTXT(str070);							// Envia o comando...
	uartTXT(atCur), uartTXC(vlrModoWF), uartTXT(atFim);							// .
}

/* Nao testado */
void espModoCx(unsigned char vlrModoCx)											// Configura o modo de transmissão. 0=Normal, 1=Transparente.
{
	unsigned char str071[]={"MODE="};
	// Comando:  AT+CIPMODE=x. 0=Normal, 1=Transparente.
	if(vlrModoCx>1) vlrModoCx=1;												// Validar valor maximo.
	vlrModoCx += '0';															// Converte para ASCII.
	uartTXT(atIni), uartTXT(atCIP), uartTXT(str071);							// Envia o comando.
	uartTXC(vlrModoCx), uartTXT(atFim);											// .
}

/* Nao testado */
void espAPCfg(void)																// Configura o SoftAP.
{
	const unsigned char str010[]={"SAP"};
//	const unsigned char str011=',';
	const unsigned char str011[]={","};
	// Comando:  AT+CWSAP_CUR=ssid,pass,canal,ecn[,numero max de conexao, ssid oculto]
	uartTXT(atIni), uartTXT(atCW0), uartTXT(str010), uartTXT(atCur);				// Envia o comando...
	uartTXT(atAs1), uartTXT(espSrvSsid), uartTXT(atAs2), uartTXT(espSrvPass);	// ...
//	uartTXT(atAs1), uartTXC(str011), uartTXC(espSrvCan), uartTXTC(str011);				// ...
	uartTXT(atAs1), uartTXT(str011), uartTXT(espSrvCan), uartTXT(str011);				// ...
//	uartTXC(espSrvEcn),	uartTXT(atFim);											// .
	uartTXT(espSrvEcn),	uartTXT(atFim);											// .
}

/* 100% :) */
unsigned char espApConectar(void)												// Conecta a um Access Point/HUB/Roteador.
{	
	unsigned char str020[]={"JAP"};
	unsigned char str021[]={"_CUR?"};
	
	unsigned char espVarTmp;													// Variavel local temporaria.
	espClearBuffer();															// Limpa o buffer de recepcao.
	// Comando: AT+CWJAP_CUR?													// Verifica se ja esta conectado.
	uartTXT(atIni), uartTXT(atCW0), uartTXT(str020);							// Envia o comando...
	uartTXT(str021), uartTXT(atFim);											// .
	__delay_ms(1000);															// Aguarda...
	espVarTmp=procString(espApSsid,espBufferRx);								// Verifica resposta.
	
	if(espVarTmp==0xFF)															// Texto nao encontrado: Nao esta conectado.
	{
		// Comando: AT+CWJAP_CUR="nome","senha"									// Conectar no Access Point (AP).
		uartTXT(atIni), uartTXT(atCW0), uartTXT(str020), uartTXT(atCur);		// Envia o comando...
		uartTXT(atAs1),	uartTXT(espApSsid), uartTXT(atAs2), uartTXT(espApPass);	// ...
		uartTXT(atAs1), uartTXT(atFim);											// .
		__delay_ms(5000);
		__delay_ms(5000);
		__delay_ms(2000);
		espVarTmp=espRetOk();													// Verifica resposta.
		return (espVarTmp);														// Retorna '1' se esta 'Ok', '0' nao esta 'Ok'.
	}
	return (1);																	// Ja esta conectado.
}

/* Nao testado */
unsigned char espApDesconectar(void)	// Desconecta de um Access Point/HUB/Roteador.
{
	const unsigned char str080[]={"QAP"};
	unsigned char espVarTmp;					// Variavel local.
	// Comando: AT+CWQAP\r\n
	uartTXT(atIni),	uartTXT(atCW0), uartTXT(str080), uartTXT(atFim);
	// Aguarda 'OK'
	__delay_ms(1500);
	espVarTmp=espRetOk();														// Verifica resposta.
	return (espVarTmp);															// Retorna '1' se esta 'Ok', '0' nao esta 'Ok'.
}

/* Nao testado */
void espMux(unsigned char vlrMux)												// Habilita(1) / Desabilita(0), Multiplas conexoes.
{
	const unsigned char str081[]={"MUX="};
	// Comando:  AT+CIPMUX=x. 0=Simples, 1=Multiplas.
	espApDesconectar();															// Antes da alteracao, todas as conexoes devem ser desconectadas.
	if(vlrMux>1) vlrMux=1;														// Validar valor maximo.
	if(vlrMux==1) espModoCx(0);													// A funcao de 'Multiplas conexoes' so funciona no modo 'normal'.
	vlrMux += '0';																// Converte valor para ASCII.
	uartTXT(atIni),	uartTXT(atCIP), uartTXT(str081), uartTXC(vlrMux);			// Envia comando...
	uartTXT(atFim);																// .
}

unsigned char lcdIp[16];// ={"000.000.000.000"};
unsigned char lcdMac[18];//={"--:--:--:--:--:--"};

/* 100% :) */
//void espIpMac(unsigned char *str15,unsigned char *vlrIp1,unsigned char *vlrMac1)// Recupera e salva em ASCII o valor do IP e MAC.
void espIpMac(void)// Recupera e salva em ASCII o valor do IP e MAC.
{	
	const unsigned char str085[]={"CIFSR"};
	const unsigned char str086[]={"P,"};
	const unsigned char str087[]={"C,"};
	
	unsigned char x=0,y=0,p=4,c=0;
	unsigned char eipVlr15[4];													// Matriz temporaria para converter ASCII em CHAR.
	unsigned char eipTst15[18];													// Matriz temporaria para buscar o IP e MAC.
	espClearBuffer();															// Limpa o buffer de recepcao.
	// Comando: AT+CIFSR\r\n
	uartTXT(atIni), uartTXT(str085), uartTXT(atFim);							// Envia o comando.
	__delay_ms(1000);															// Aguarda a resposta.
	/* Recupera valor IP */
//	retValorStr(str15,str086,eipTst15,15,3);									// Salva 15 caracteres apos ocorrencia com offset de 3 caracteres.
	retValorStr(espBufferRx,str086,eipTst15,15,3);								// Salva 15 caracteres apos ocorrencia com offset de 3 caracteres.
	for(y=0;y<4;y++)eipVlr15[y]='\0';											// Limpa variavel de conversao.
	y=0;																		// Reinicia variavel de busca.
	while(p>0)																	// Laco para resgatar os numeros do IP.
	{
		do																		// Laco para montar valor do grupo IP.
		{
			eipVlr15[y]=eipTst15[x];											// Compoe o valor (pode ser 1, 2 ou 3 digitos).
			if(eipTst15[x]=='\0')eipTst15[x]='0';
			if(eipTst15[x]>='0' & eipTst15[x]<='9') lcdIp[x]=eipTst15[x];		// Verifica se sao valores de '0' a '9'.
			x++;																// Incrementa o ponteiro da matriz de busca.
			y++;																// Incrementa o ponteiro da matriz de conversao.
		}while(eipTst15[x]>='0' & eipTst15[x]<='9');							// Repete enquanto for numeros.
		if(p>1) lcdIp[x]='.';													// Acrescenta o separador na string.
//		vlrIp1[4-p]=asc2Hex(eipVlr15);											// Converte o(s) digito(s) ASCII em hexadecimal.
		x++;																	// Incrementa o ponteiro da matriz de busca.
		for(y=0;y<4;y++)eipVlr15[y]='\0';										// Limpa variavel de conversao.
		y=0;																	// Reinicia variavel de busca.
		p--;																	// Proximo grupo de numero do IP.
	}
	/* Recupera valor MAC */
//	retValorStr(str15,str087,eipTst15,17,3);									// Salva 17 caracteres apos ocorrencia com offset de 3 caracteres.
	retValorStr(espBufferRx,str087,eipTst15,17,3);								// Salva 17 caracteres apos ocorrencia com offset de 3 caracteres.
	x=0;																		// Reinicia variavel da dezena.
	y=0;																		// Reinicia variavel da unidade.
	p=0;																		// Reinicia variavel de laco.
	
	for(p=0;p<6;p++)															// Laco para os grupos do MAC.
	{
		if(eipTst15[c]=='\0')eipTst15[c]='0';
		if(eipTst15[c+1]=='\0')eipTst15[c]='0';
		x=eipTst15[c];															// Salva valor da dezena do grupo numerico do MAC.
		y=eipTst15[c+1];														// Salva valor da unidade do grupo numerico do MAC.
		lcdMac[c]=x;															// Salva dezena em ASCII para exibir no LCD.
		lcdMac[c+1]=y;															// Salva unidade em ASCII para exibir no LCD.
		if(p<5)lcdMac[c+2]=':';
		if(x>0x60 && x<0x67)x-=0x57;											// Converte a dezena: 'a' ate 'f' em 0x0A ate 0x0F
		if(x>0x41 && x<0x47)x-=0x37;											// Converte a dezena: 'A' ate 'F' em 0x0A ate 0x0F
		if(x>='0' && x<='9')x-='0';												// Converte a dezena: '0' ate '9' em 0x00 ate 0x09
		if(y>0x60 && y<0x67)y-=0x57;											// Converte a unidade: 'a' ate 'f' em 0x0A ate 0x0F
		if(y>0x41 && y<0x47)y-=0x37;											// Converte a unidade: 'A' ate 'F' em 0x0A ate 0x0F
		if(y>='0' && y<='9')y-='0';												// Converte a unidade: '0' ate '9' em 0x00 ate 0x09
//		vlrMac1[p]=(x<<4)|y;													// Formata e salva o valor MAC.
		c+=3;																	// Proximo grupo de numero do MAC.
	}
}

/* Nao testado */
void espServidor(unsigned char vlrSrv, unsigned int vlrPorta)
{
	const unsigned char str082[]={"SERVER="};
	unsigned char vlrPortaAsc[5];
	
	int2Asc(vlrPorta,vlrPortaAsc,4);											// Converte o valor em ASCII.
	
	/* Comando:  AT+CIPSERVER=x,y. x=0 Desliga servidor. 
	 * x=1 e y=333 (padrao) Cria servidor mais sua porta. */
	if(vlrSrv>1) vlrSrv=1;														// Validar valor maximo.
	vlrSrv += '0';																// Converte para ASCII.
	
	if(vlrSrv=='1')																// Cria o servidor.
	{ 
		espAPCfg();																// Configura o AP.
		espModoWF(2);															// Ativa o modo SoftAP.
		espMux(1);																// Para criar o servidor é necessario multiplas conexoes.
		uartTXT(atIni),	uartTXT(atCIP), uartTXT(str082);						// Envia comando...
		uartTXC(vlrSrv), uartTXT(vlrPortaAsc), uartTXT(atFim);					// .
	}
	if(vlrSrv=='0')																// Remove o servidor.
	{
		uartTXT(atIni),	uartTXT(atCIP), uartTXT(str082);						// Envia comando...
		uartTXC(vlrSrv), uartTXT(atFim);										// .
	}
}

/* Nao testado */
void espListaWiFi(void)
{
	const unsigned char str091[]={"LAP"};
	// Comando: AT+CWLAP\r\n
	uartTXT(atIni), uartTXT(atCW0), uartTXT(str091), uartTXT(atFim);				// Envia comando.
}

/* Ok 100% */
void __interrupt() espInt()														// Interrupcao da UART.
{
    unsigned char oldStatus = STATUS;											// Copia registro 'Status' por seguranca.
    INTCONbits.GIE = 0;															// Desabilita Interrupcao Global.
	
    if(PIR1bits.RCIF==1)														// Verifica se a interrupcao eh da recepcao.
	{
        espBufferRx[Contador] = RCREG;											// Copia os dados e ...
        Contador++;																// incrementa o contador do Buffer.
        if(RCSTAbits.OERR)														// Verifica se ocorreu algum erro. Se ocorrer, reabilita.
        {
            RCSTAbits.CREN = 0;													// Desabilita recepcao.
            NOP();																// Aguarda 1 ciclo de maquina.
            RCSTAbits.CREN = 1;													// Habilita recepcao.
        }
        if(Contador == espBufferSize) Contador = 0;								// Chegou no fim do buffer? Reinicia a variavel 'Contador'.
    }
    INTCONbits.GIE = 1;															// Habilita Interrupcao Global.
    STATUS = oldStatus;															// Restaura o registro de 'Status'.
}

unsigned char espWebTx(void)
{
	unsigned char varTeste;
	unsigned char str001[]={"START="};
	unsigned char str002[]={"TCP"};
	unsigned char str003  =',';
	unsigned char str004[]={"Web: Ok"};
	unsigned char str005[]={"SEND=202"};
	unsigned char str006[]={"Web: Tx"};
	unsigned char str007[]={"Web:NTx"};
	unsigned char str008[]={"Web:NOk"};
	
	espClearBuffer();															// Limpa o buffer de recepcao.
	
	// Comando: AT+CIPSTART="TCP","api.thingspeak.com",80
	uartTXT(atIni), uartTXT(atCIP), uartTXT(str001), uartTXT(atAs1);			// Envia comando...
	uartTXT(str002), uartTXT(atAs2),uartTXT(tSpkDominio), uartTXT(atAs1);		// ...
	uartTXC(str003), uartTXT(tSpkPorta), uartTXT(atFim);						// .
	__delay_ms(2000);															// Aguarda resposta.
	varTeste=espRetOk();														// Verifica resposta.
	if(varTeste)																// Se 'Ok'....
	{
		lcdTexto(str004,1,1);													// Envia info ao LCD.
		espClearBuffer();														// Limpa o buffer de recepcao.
		// Comando: AT+CIPSEND=202
		uartTXT(atIni), uartTXT(atCIP), uartTXT(str005),uartTXT(atFim);			// Envia comando.
		__delay_ms(2000);														// Aguarda resposta...
		varTeste=espRetOk();													// Verifica resposta.
		if(varTeste)															// Se 'Ok'....
		{
			lcdTexto(str006,1,1);												// Envia info ao LCD.
			uartTXT(thSpkL1), uartTXT(thSpkL2), uartTXT(thSpkL3);				// Envia comando...
			uartTXT(thSpkL4), uartTXT(tSpkKeyWr), uartTXT(atFim);				// ...
			uartTXT(thSpkL5), uartTXT(thSpkL6),	uartTXT(thSpkL7);				// ...
			uartTXT(campo1), uartTXT(thSpkL8), uartTXT(campo2), uartTXT(atFim);	// .
			contarTx++;															// Quantidade de TX bem sucedidas.
		}	
		else lcdTexto(str007,1,1);												// Nao foi transmitido para WEB.
	}
	else lcdTexto(str008,1,1);													// WEB Indisponivel.
	return(varTeste);
}

void espNTP(unsigned char *vlrDia, unsigned char *vlrMes, unsigned char *vlrAno, unsigned char *vlrHora, unsigned char *vlrMin)		// Recupera a data e hora atual da rede via SNTP ou NTP.
{
	/* Servidor(es) SNTP ou NTP */
	const unsigned char srv1[]={"a.ntp.br"};									// Servidor primario NTP.
	const unsigned char srv2[]={"b.ntp.br"};									// Servidor secundario NTP.
	const unsigned char srv3[]={"c.ntp.br"};									// Servidor terciario NTP.
	
//	const unsigned char srv1[]={"0.br.pool.ntp.org"};							// Servidor primario NTP.
//	const unsigned char srv2[]={"1.br.pool.ntp.org"};							// Servidor secundario NTP.
//	const unsigned char srv3[]={"2.br.pool.ntp.org"};							// Servidor terciario NTP.
	
	unsigned char dateVarASC[25];												// 
	
	unsigned char str001[]={"SNTPCFG=1,-3,"};
	unsigned char str002[]={"SNTPTIME?"};
	unsigned char str003[]={"E:"};

	/* Aviso: Se a data recuperada for inferior a atual, a rede esta bloqueando o acesso. */
	// Comando <questao>: AT+CIPSNTPCFG?
	// Comando <ajuste>: AT+CIPSNTPCFG=enable(1) disable(0),time zone,server 1,server 2,server 3
	// Comando: AT+CIPSNTPCFG=1,-3,"a.ntp.br","b.ntp.br","c.ntp.br"
	uartTXT(atIni), uartTXT(atCIP), uartTXT(str001),uartTXT(atAs1);				// Envia comando...
	uartTXT(srv1), uartTXT(atAs2),uartTXT(srv2),uartTXT(atAs2),uartTXT(srv3);	// ...
	uartTXT(atAs1),uartTXT(atFim);												// .
	__delay_ms(2000);															// Aguarda...
	// Comando:  AT+CIPSNTPTIME?
	uartTXT(atIni), uartTXT(atCIP), uartTXT(str002),uartTXT(atFim);				// Envia comando.
	espClearBuffer();															// Limpa o buffer de recepcao.
	__delay_ms(2000);															// Aguarda resposta...
	retValorStr(espBufferRx,str003,dateVarASC,24,2);							// Salva os 24 caracteres apos ocorrencia com offset de 2 caracteres.
	// Mon = Segunda		Jan = Janeiro		Aug = Agosto
	// Tue = Terca			Feb = Fevereiro		Sep = Setembro
	// Wed = Quarta			Mar = Marco			Oct = Outubro
	// Thu = Quinta			Apr = Abril			Nov = Novembro
	// Fri = Sexta			May = Maio			Dec = Dezembro
	// Sat = Sabado			Jun = Junho
	// Sun = Domingo		Jul = Julho
	unsigned char vldDDS;														// Variavel do dia da semana.
	
	/* Dia da Semana */
	switch(dateVarASC[0])														// Recupera em ASCII o dia da semana (Dom=1).
	{
		case 'M':																// Mon
			vldDDS=2;															// Segunda
			break;																// Interrompe o processo.
		case 'T':																// Tue ou Thu
			if(dateVarASC[1]=='u')	vldDDS=3;									// Terca
			else					vldDDS=5;									// Quinta
			break;																// Interrompe o processo.
		case 'W':																// Wed
			vldDDS=4;															// Quarta
			break;																// Interrompe o processo.
		case 'F':																// Fri
			vldDDS=5;															// Sexta
			break;																// Interrompe o processo.
		case 'S':																// Sat ou Sun
			if(dateVarASC[1]=='a')	vldDDS=6;									// Sabado
			else					vldDDS=1;									// Domingo
			break;																// Interrompe o processo.
		default:
			vldDDS=0;															// Dado invalido.
			break;																// Interrompe o processo.
	}
	
	/* Mes */
	switch(dateVarASC[4])														// Recupera e salva em ASCII o mes.
	{
		case 'J':																// Janeiro, Junho ou Julho
			if(dateVarASC[5]=='a')		vlrMes[0]='0',vlrMes[1]='1';			// Janeiro
			else if(dateVarASC[6]=='n')	vlrMes[0]='0',vlrMes[1]='6';			// Junho
			else						vlrMes[0]='0',vlrMes[1]='7';			// Julho
			break;																// Interrompe o processo.
		case 'F':																// Fevereiro
			vlrMes[0]='0',vlrMes[1]='2';
			break;																// Interrompe o processo.
		case 'M':																// Marco ou Maio
			if(dateVarASC[6]=='r')		vlrMes[0]='0',vlrMes[1]='3';			// Marco
			else						vlrMes[0]='0',vlrMes[1]='5';			// Maio
			break;																// Interrompe o processo.
		case 'A':																// Abril ou Agosto
			if(dateVarASC[6]=='r')		vlrMes[0]='0',vlrMes[1]='4';			// Abril
			else						vlrMes[0]='0',vlrMes[1]='8';			// Agosto
			break;																// Interrompe o processo.
		case 'S':																// Setembro
			vlrMes[0]='0',vlrMes[1]='9';
			break;																// Interrompe o processo.
		case 'O':																// Outubro
			vlrMes[0]='1',vlrMes[1]='0';
			break;																// Interrompe o processo.
		case 'N':																// Novembro
			vlrMes[0]='1',vlrMes[1]='1';
			break;																// Interrompe o processo.
		case 'D':																// Dezembro
			vlrMes[0]='1',vlrMes[1]='2';
			break;																// Interrompe o processo.
		default:
			vlrMes[0]='_',vlrMes[1]='_';										// Dado invalido.
			break;																// Interrompe o processo.
	}
	//           11111111112222
	// 012345678901234567890123
	// Sat Aug 21 18:32:10 2021
	vlrHora[0]='_',vlrHora[1]='_';												// Valor padrao para dado invalido.
	vlrMin[0]='_',vlrMin[1]='_';												// Valor padrao para dado invalido.
	vlrDia[0]='_',vlrDia[1]='_';												// Valor padrao para dado invalido.
	vlrAno[0]='_',vlrAno[1]='_';												// Valor padrao para dado invalido.
	if(dateVarASC[11]!='\0')vlrHora[0]=dateVarASC[11],vlrHora[1]=dateVarASC[12];// Salva Hora em ASCII.
	if(dateVarASC[14]!='\0')vlrMin[0]=dateVarASC[14],vlrMin[1]=dateVarASC[15];	// Salva Minuto em ASCII.
	if(dateVarASC[8]!='\0')vlrDia[0]=dateVarASC[8], vlrDia[1]=dateVarASC[9];	// Salva Dia em ASCII.
	if(dateVarASC[22]!='\0') vlrAno[0]=dateVarASC[22],vlrAno[1]=dateVarASC[23];	// Salva Ano em ASCII.
}

void espDataWeb(unsigned char *vlrDia, unsigned char *vlrMes, unsigned char *vlrAno, unsigned char *vlrHora, unsigned char *vlrMin)
{
	unsigned char dateASC[36];												// 
	unsigned char str130[]={"Date:"};
	//           1111111111222222222233333
	// 01234567890123456789012345678901234
	// Date: Mon, 23 Aug 2021 19:48:31 GMT
	retValorStr(espBufferRx,str130,dateASC,34,6);								// Salva os 34 caracteres apos ocorrencia com offset de 6 caracteres.
	
	/* Mes */
	switch(dateASC[14])															// Recupera e salva em ASCII o mes.
	{
		case 'J':																// Janeiro, Junho ou Julho
			if(dateASC[15]=='a')		vlrMes[0]='0',vlrMes[1]='1';			// Janeiro
			else if(dateASC[16]=='n')	vlrMes[0]='0',vlrMes[1]='6';			// Junho
			else						vlrMes[0]='0',vlrMes[1]='7';			// Julho
			break;																// Interrompe o processo.
		case 'F':																// Fevereiro
			vlrMes[0]='0',vlrMes[1]='2';
			break;																// Interrompe o processo.
		case 'M':																// Marco ou Maio
			if(dateASC[16]=='r')		vlrMes[0]='0',vlrMes[1]='3';			// Marco
			else						vlrMes[0]='0',vlrMes[1]='5';			// Maio
			break;																// Interrompe o processo.
		case 'A':																// Abril ou Agosto
			if(dateASC[16]=='r')		vlrMes[0]='0',vlrMes[1]='4';			// Abril
			else						vlrMes[0]='0',vlrMes[1]='8';			// Agosto
			break;																// Interrompe o processo.
		case 'S':																// Setembro
			vlrMes[0]='0',vlrMes[1]='9';
			break;																// Interrompe o processo.
		case 'O':																// Outubro
			vlrMes[0]='1',vlrMes[1]='0';
			break;																// Interrompe o processo.
		case 'N':																// Novembro
			vlrMes[0]='1',vlrMes[1]='1';
			break;																// Interrompe o processo.
		case 'D':																// Dezembro
			vlrMes[0]='1',vlrMes[1]='2';
			break;																// Interrompe o processo.
		default:
			vlrMes[0]='_',vlrMes[1]='_';										// Dado invalido.
			break;																// Interrompe o processo.
	}
	vlrHora[0]='_',vlrHora[1]='_';												// Valor padrao para dado invalido.
	vlrMin[0]='_',vlrMin[1]='_';												// Valor padrao para dado invalido.
	vlrDia[0]='_',vlrDia[1]='_';												// Valor padrao para dado invalido.
	vlrAno[0]='_',vlrAno[1]='_';												// Valor padrao para dado invalido.
	if(dateASC[23]!='\0') vlrHora[0]=dateASC[23], vlrHora[1]=dateASC[24];		// Salva Hora em ASCII.
	if(dateASC[26]!='\0') vlrMin[0] =dateASC[26], vlrMin[1] =dateASC[27];		// Salva Minuto em ASCII.
	if(dateASC[11]!='\0') vlrDia[0] =dateASC[11], vlrDia[1] =dateASC[12];		// Salva Dia em ASCII.
	if(dateASC[20]!='\0') vlrAno[0] =dateASC[20], vlrAno[1] =dateASC[21];		// Salva Ano em ASCII.
}

void subDHT(void)
{
	unsigned char ascii[5],x;
	unsigned int humi,temp;
	
	for(x=0;x<5;x++)ascii[x]='\0';
	for(x=0;x<5;x++)campo1[x]='\0';
	for(x=0;x<5;x++)campo2[x]='\0';
	
	dhtxxIniciar(&PORTC,0);

	dhtxx(DHT11,&humi,&temp);

	int2Asc(humi,ascii,3);
	ascii[3]=ascii[2];
	ascii[2]='.';
	for(x=0;x<5;x++)campo1[x]=ascii[x];
	lcdTexto(ascii,4,1);

	int2Asc(temp,ascii,3);
	ascii[3]=ascii[2];
	ascii[2]='.';
	for(x=0;x<5;x++)campo2[x]=ascii[x];
	lcdTexto(ascii,4,10);
}

void subIPMAC(void)
{
	unsigned char str100[]={"IP="};
	unsigned char str101[]={"MC="};
	unsigned char str102[]={"Cliente: IP e MAC   "};
	unsigned char str103[]={"                    "};
	unsigned char ip_[4];														// Variavel para IP em ASCII.
	unsigned char mac[6];														// Variavel para MAC em ASCII.
//	espIpMac(espBufferRx,ip_,mac);												// Recupera e salva em ASCII o valor do IP e MAC.
	espIpMac();												// Recupera e salva em ASCII o valor do IP e MAC.
	lcdTexto(str102,1,1);														// Titulo.
	lcdTexto(str100,2,1);														// Envia info ao LCD.
	lcdTexto(str101,3,1);														// Envia info ao LCD.
	lcdTexto(str103,4,1);														// Limpa a linha 4 do LCD.
	
//	if(sizeString(lcdIp)>0) lcdTexto(lcdIp,2,4);								// Envia valor ao LCD.
//	if(sizeString(lcdMac)>0) lcdTexto(lcdMac,3,4);								// Envia valor ao LCD.
	lcdTexto(lcdIp,2,4);								// Envia valor ao LCD.
	lcdTexto(lcdMac,3,4);								// Envia valor ao LCD.
}

void subInic(void)
{
	unsigned char str102[]={"Iniciando"};
//	unsigned char str103[]={"."};
	unsigned char str103='.';
	unsigned char str107[]={"                    "};
	unsigned char varTeste;														// Variavel local temporaria.
//	for(varTeste=0;varTeste<4;varTeste++)contador[varTeste]='\0';				// Limpa variavel.
	lcdTexto(str102,1,1);														// Envia info ao LCD.
	for(varTeste=0;varTeste<10;varTeste++)										// Laco para aguardar inicializacao do ESP.
	{
		lcdCaracter(str103,1,(10+varTeste));									// Envia info ao LCD.
		__delay_ms(50);															// Aguarda...
	}
	lcdTexto(str107,1,1);
}

void subWifi(void)
{
	unsigned char str104[]={"ESP:  ?"};
	unsigned char str105[]={" Ok"};
	unsigned char str106[]={"Nok"};
	unsigned char varTeste;														// Variavel local temporaria.
	lcdTexto(str104,1,1);														// Envia info ao LCD.
	varTeste=espOperacional();													// Verifica se o ESP esta operacional.
//	__delay_ms(1000);
	if(varTeste)lcdTexto(str105,1,5);											// Esta 'Ok'.
	else lcdTexto(str106,1,5);													// ESP nao esta operacional.
}

void subHub(void)
{
	unsigned char str107[]={"Hub:  ?"};
	unsigned char str108[]={" Ok"};
	unsigned char str109[]={"Nok"};
	
	unsigned char varTeste;														// Variavel local temporaria.
	lcdTexto(str107,1,1);														// Envia info ao LCD.
	varTeste=espApConectar();													// Verifica se o ESP conectou ao roteador.
//	__delay_ms(1000);
	if(varTeste)lcdTexto(str108,1,5);											// Esta 'Ok'.
	else lcdTexto(str109,1,5);													// ESP nao se conectou ao roteador.
}

void subInt(void)
{
	INTCONbits.GIE=1;															// Habilita Interrupcao Global.
	INTCONbits.PEIE=1;															// Habilita Interrupcao dos Perifericos.
	PIE1bits.RCIE=1;															// Habilita Interrupcao de recepcao.
}

void subInfo(void)
{
	unsigned char vAt[]={"0.0.0.0"};											// Formato da versao do AT.
	unsigned char vSdk[]={"0.0.0"};												// Formato da versao do SDK.
	unsigned char vBin[]={"Xxxxx 00"};											// Formato da versao do BIN.
	unsigned char str140[]={"AT ="};											// Texto base.
	unsigned char str141[]={"SDK="};											// Texto base.
	unsigned char str142[]={"BIN="};											// Texto base.
	unsigned char str143[]={"Versao Firmware:    "};							// Titulo.
	espInfo(vAt,vSdk,vBin);														// Recupera a versao do ESP.
	lcdTexto(str143,1,1);														// Envia o Titulo.
	lcdTexto(str140,2,1),lcdTexto(vAt,2,5);										// Envia a versao do AT.
	lcdTexto(str141,3,1),lcdTexto(vSdk,3,5);									// Envia a versao do SDK.
	lcdTexto(str142,4,1),lcdTexto(vBin,4,5);									// Envia a versao do Bin.
}

void subNtp(void)
{
	unsigned char dia[]={"__"};													// Variavel para valores em ASCII.
	unsigned char mes[]={"__"};													// Variavel para valores em ASCII.
	unsigned char ano[]={"__"};													// Variavel para valores em ASCII.
	unsigned char hora[]={"__"};												// Variavel para valores em ASCII.
	unsigned char min[]={"__"};													// Variavel para valores em ASCII.													// Variavel para valores em ASCII.

	espNTP(dia,mes,ano,hora,min);												// Recupera a data e hora atual da rede via SNTP ou NTP.
	lcdTexto("NTP:                ",3,1);										// Limpa a linha do LCD.

	lcdTexto(hora,3,6);															// Envia a 'Hora' ao LCD.
	lcdTexto(min,3,9);															// Envia a 'Minuto' ao LCD.
	lcdCaracter(':',3,8);														// Envia valor ao LCD.

	lcdTexto(dia,3,12);															// Envia a 'Dia' ao LCD.
	lcdTexto(mes,3,15);															// Envia a 'Mes' ao LCD.
	lcdTexto(ano,3,18);															// Envia a 'Ano' ao LCD.
	lcdCaracter('/',3,14);														// Envia valor ao LCD.
	lcdCaracter('/',3,17);														// Envia valor ao LCD.
}

void subTempo(unsigned char tempoTmp)
{
	unsigned char tmpTTmp;
	for(tmpTTmp=0;tmpTTmp<tempoTmp;tmpTTmp++)
	{
		__delay_ms(500);
		lcdCaracter(0x7E,1,20);
		__delay_ms(500);
		lcdCaracter(0x7F,1,20);
	}
}

void main(void)
{
//	unsigned char contador[5];													// Variavel para contar as TX em ASCII.
	
	/*  Inicializando */
	uartIniciar115k();															// Inicia a USART em 115kbps.
	subInt();																	// Sub: Liga interrupcao.
	lcdIniciar(&PORTD,lcd20x4);													// Inicia e acessa o LCD.

	/* Delay para o ESP */
	subInic();																	// Sub: Aguarda a inicializacao do ESP.
	
	/* Inicia WiFi */
	// Precisa colocar: AT+CWMODE=1 (Modo Client) em modo AP nao conecta no thingSpeak
	espModoWF(1);																// Modo: Estacao(Client).
	subWifi();																	// Sub: Verifica ESP.
	__delay_ms(1500);

	/* Inicia Roteador */
	subHub();																	// Sub: Conecta no roteador.
	__delay_ms(1500);
	
	/* iNFO */
	subInfo();																	// Sub: Carrega versao do fimware.
	__delay_ms(1500);
	
	/* IP e MAC */
	subIPMAC();																	// Resgata o valor Ip e MAC do ESP.
	__delay_ms(1500);
	
	/* DHT11 */
	unsigned char str112[]={"00.0%H   00.0\xDF C"};								// Formata o texto.
	str112[13]=0xDF;															// Agrega o simbolo de grau.
	lcdTexto(str112,4,1);														// Envia info ao LCD.

	/* Dia, Mes, Ano, Hora e Minuto */
	subNtp();
	
	/* WEB */
	unsigned xyz=60;
	unsigned char tttAsc[]={"00"};
	unsigned char contador[]={"0000"};;											// Variavel para contar as TX em ASCII.

	unsigned char str110[]={"Web:                "};
	unsigned char str111[]={"Web: "};
	
	lcdTexto(str110,1,1);
	while(1)
	{
		subDHT();
				
		subTempo(1);

		int2Asc(xyz,tttAsc,2);
		
		lcdTexto(tttAsc,1,6);
		
		int2Asc(contarTx,contador,4);
		lcdTexto(contador,1,15);
		
		
		if(xyz==0)
		{
			lcdTexto(str111,1,1);
			if(espWebTx())contarTx++;
//			__delay_ms(2500);
//			espDataWeb(dia,mes,ano,hora,min);												// 
//			lcdTexto(hora,3,6);															// Envia a 'Hora' ao LCD.
//			lcdTexto(min,3,9);															// Envia a 'Minuto' ao LCD.
//			lcdCaracter(':',3,8);														// Envia valor ao LCD.
//			lcdTexto(dia,3,12);															// Envia a 'Dia' ao LCD.
//			lcdTexto(mes,3,15);															// Envia a 'Mes' ao LCD.
//			lcdTexto(ano,3,18);															// Envia a 'Ano' ao LCD.
//			lcdCaracter('/',3,14);														// Envia valor ao LCD.
//			lcdCaracter('/',3,17);														// Envia valor ao LCD.
//			xyz=59;
			xyz=61;
		}
		xyz--;
	}
}
