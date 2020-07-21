//Programa para un robot de plataforma tipo Talrik Junior que busca una bola roja entre
//99 bolas blancas de ping-pong en un rign de 1.5m de diámetro

#define PORTC @0x07
#define TRISC @0x87

//Salidas
//RC1,RC0--> Motor Derecho, Quieto: 00,  Avance:  01, Retroceda:  10,  No Importa: 11
//RC3,RC2--> Motor Izquierdo, Quieto: 00,  Avance:  01, Retroceda:  10,  No Importa: 11
//RC4-->Trampa de Bolas
//RC5-->Chicharra

//Entradas
//RB0--> IR derecho
//RB1--> IR izquierdo
//RB2--> IR trasero
//RB3--> uswitch derecho
//RB4--> uswitch izquierdo
//RB5--> CDS (luego del comparador)

void retardo(void);

    
main()
{
    set_bit( STATUS, RP0 );// Apuntamos al segundo banco de registros
    //set_tris_c( 0 );// Ajustamos las líneas del puerto C como salida
    //clear_bit( STATUS, RP0 );// Apunstamos el primer banco de registros
    set_tris_c(0x00);
    set_tris_b(0xFF);
    output_high_port_c(5);
    retardo();
    output_high_port_c(0);
    output_high_port_c(4);
    
}


void retardo(void)
{
    char cContador1; 
    char cContador2;
    cContador1 = 0;// Damos el valor 0 a la variable bContador1
    while( cContador1 < 150 )
    {
        cContador1++;
        while( cContador2++ < 200 )
        {
            nop();  // Ejecutamos un ciclo de inactividad
        }
    }
}