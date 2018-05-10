/*=========================================
*Juego: Ahorcado
*Tiempo: 30-40 minutos aproximados
*Nota: Hay cosas que se pueden simplificar
=========================================*/
#include<stdio.h>
#include<string.h>

struct Palabra

    {
        char laPalabra[20],listaGuiones[20];
    };

const void bienvenida();
const void juego();
void setPalabra(Palabra *p);
inline int setVidas(Palabra *p);
void setGuion(Palabra *p);
const inline void getGuiones(Palabra *p);
void buscarCoincidencia(Palabra *p);
const void mensajeFinal(Palabra *p,int cantidadVidas);


int main()

    {
        int seguir;
        do
            {
                bienvenida();
                juego();
                printf("Pulse 1 si desea seguir jugando: ");
                scanf("%d",&seguir);
            }while(seguir==1);
        return 0;
    }

const void bienvenida()

{
    printf(
            "\n _________"
            "\n|  |                  Ahorcado"
            "\n|  0                  --------"
            "\n| /|\\"
            "\n| / \\ "
            "\n|"
            "\n|                     by yony!"
            "\n\n\n\n\n"
            );
}

const void juego()

    {
        Palabra nuevaPalabra,*p=&nuevaPalabra;
        setPalabra(p);
        int cantidadVidas=setVidas(p);
        setGuion(p);
        do
            {
                printf("\n\nTe quedan %d vidas\n\n",cantidadVidas);
                getGuiones(p);
                buscarCoincidencia(p);
                if(strcmp(p->listaGuiones,p->laPalabra)==0)
                    break;
                cantidadVidas--;
            }while(cantidadVidas>0);
        mensajeFinal(p,cantidadVidas);
    }

void setPalabra(Palabra *p)

    {
        fflush(stdin);
        printf("Ingrese la palabra que debe adivinarse: ");
        scanf("%20s",p->laPalabra);
    }

inline int setVidas(Palabra *p)

    {
        return strlen(p->laPalabra)*2;
    }

void setGuion(Palabra *p)

    {
        for(int letra=0;letra<=strlen(p->laPalabra);letra++)
            {
                if(letra<strlen(p->laPalabra))
                    p->listaGuiones[letra]='_';
                else
                    p->listaGuiones[letra]='\0';
            }
    }

const inline void getGuiones(Palabra *p)

    {
        printf("\n");
        for(int letra=0;letra<strlen(p->listaGuiones);letra++)
            {
                printf("%c ",p->listaGuiones[letra]);
            }
    }

void buscarCoincidencia(Palabra *p)

    {
        char miIntento[20],miLetra,laLetra;
        fflush(stdin);
        printf("\n\nIngrese una letra o la palabra completa: ");
        scanf("%20s",miIntento);
        if(strlen(miIntento)==1)
            {
                miLetra=miIntento[0];
                for(int letra=0;letra<strlen(p->laPalabra);letra++)
                    {
                        laLetra=p->laPalabra[letra];
                        if(miLetra==laLetra)
                            p->listaGuiones[letra]=miLetra;
                    }
            }
        else if(strcmp(miIntento,p->laPalabra)==0)
            for(int letra=0;letra<strlen(p->laPalabra);letra++)
                p->listaGuiones[letra]=p->laPalabra[letra];
    }

const void mensajeFinal(Palabra *p,int cantidadVidas)

    {
        printf("\n\n\n\n\n\n**************************************");
        if(cantidadVidas>0)
                printf("\n***    Felicidades, acertaste!!    ***");
        else
                printf("\n***    Mala suerte, perdiste!!!    ***");
       printf("\n**************************************"
              "\n\nLa palabra era '%s'\n\n",p->laPalabra);
    }
