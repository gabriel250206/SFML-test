#include <SFML/Graphics.hpp>
#include "Personaje.hpp"
#include "Enemigo.hpp"
#include "Plataformas.hpp"
#include "Armas.hpp"
#include "back.hpp"
#include "Obstaculos.hpp"
#include "Boss.hpp"
#include <iostream>
#include <vector>
#include<stdlib.h>
#include<time.h>
#include <fstream>
#include <SFML/Audio.hpp>
using namespace sf;




void Juego(RenderWindow &window, Personaje &adan){
   

}


typedef struct record {
    char char1;
    char char2;
    char char3;

    float score;

} registro;



void createEmpty() {

    std::string filename = "assets/score.bin";

    std::cout << "Creating empty records\n";

    registro registro1;


    registro1.char1 = ' ';
    registro1.char2 = ' ';
    registro1.char3 = ' ';

    registro1.score = 0.0f;


    std::ofstream out(filename, std::ios::binary);


    for (int i = 0; i < 5; i++) {
        out.write(reinterpret_cast<const char*>(&registro1), sizeof(registro));
    }

    out.close();

}


void readAndWriteNames(bool escribir, Personaje adan) {


    registro registros[5];


    std::string filename = "assets/score.bin";

    std::ifstream in(filename, std::ios::binary);
  
    for (int i = 0; i < 5; i++) {
        in.read(reinterpret_cast<char* >(&(registros[i])), sizeof(registro));
    }
    in.close();

    if(!escribir){
        for (int i = 0; i < 5; i++) {

        std::cout << registros[i].char1 << registros[i].char2 << registros[i].char3 << " score: " << registros[i].score << "\n";

    }
    cout<<endl;
}
    

    if(escribir){
        string nombre;
        otra:
        std::cout << "escribe tres letras"<<endl;
        cin>>nombre;
        if (nombre.size()>3){
            cout<<" solo 3 letras"<<endl;
            goto otra;
        }
    // registros[3].char1 = 'A';
    // registros[3].char2 = 'A';
    // registros[3].char3 = 'A';

    // registros[3].score = 10.10f;
    int este=5;
    for(int i=4;i>=0;i--){
        if(registros[i].score<=adan.puntaje)este--;
    }
    if(este<5){
        for(int i=4;i>este;i--){
            registros[i]=registros[i-1];        
        }
    }
    registros[este].char1=nombre[0];
    registros[este].char2=nombre[1];
    registros[este].char3=nombre[2];
    registros[este].score=adan.puntaje;

        


    std::ofstream out(filename, std::ios::binary);

    for (int i = 0; i < 5; i++) {
        out.write(reinterpret_cast<const char*>(&(registros[i])), sizeof(registro));
    }

    out.close();


    std::cout << "Writing updated records\n";


    for (int i = 0; i < 5; i++) {

        std::cout << registros[i].char1 << registros[i].char2 << registros[i].char3 << " score: " << registros[i].score << "\n";

    }

    }
    


}



// int main()
// {
    

//     createEmpty();
//     readAndWriteNames();
// }


int main()
{
    RenderWindow window(VideoMode(500, 500), "le contre");
    window.setFramerateLimit(1000);
    Personaje adan(300);
    int x=1;
    bool escribir;
    Inicio iniciador;
    //createEmpty();
    while(window.isOpen()){
        Event event;
        iniciador.drawTo(window);
        while(window.pollEvent(event)){
            if(event.type==Event::Closed)
                window.close();
            if(event.type==Event::KeyPressed){
                if(event.key.code==Keyboard::W ){
                    x--;
                }
                if(event.key.code==Keyboard::S ){
                    x++;
                }
                if(event.key.code==Keyboard::Enter){
                    if(x==1){
                        
                         Outro finalizar;
    
    //Boss lucy(Vector2f{400,400});
    //Barrera primero(Vector2f{200,0});
    //PisoLava segundo(Vector2f{400,460});
    //segundo.setExtention(100);
    vector<Barrera>obstaculos;

    //obstaculos.push_back(primero);
    //obstaculos.push_back(segundo);
    vector<Enemigo>hongos;
    Enemigo nuevo(Vector2f{448,136});
    nuevo.movimiento=false;
    hongos.push_back(nuevo);
    
    for(int i=0;i<3;i++){
        int primero=(rand() %350)+1000;
        Enemigo* serpiente= new Rapido(primero);
        hongos.push_back(*serpiente);
    }
    for(int i=0;i<3;i++){
        int primero=rand() %350+4000;
        Fuerte* serpiente= new Fuerte(primero);
        hongos.push_back(*serpiente);
    }

    
    
    
    // primero=rand() %400+100;
    // Enemigo lilith(primero);
    vector<Principal*>dropeadas;
    vector<Plataforma> plataformeo;


    
    Plataforma base2(Vector2f{400,200});
    Plataforma base3(Vector2f{300,350});
    Plataforma base(Vector2f{650,350});
    plataformeo.push_back(base);
    plataformeo.push_back(base2);
    plataformeo.push_back(base3);
    base.actualTexture.setPosition(Vector2f{1089,258});
    base2.actualTexture.setPosition(Vector2f{865,412});
    base3.actualTexture.setPosition(Vector2f{963,150});
    plataformeo.push_back(base);
    plataformeo.push_back(base2);
    plataformeo.push_back(base3);
    base.actualTexture.setPosition(Vector2f{1200,360});
    base2.actualTexture.setPosition(Vector2f{1460,250});
    base3.actualTexture.setPosition(Vector2f{1636,145});
    plataformeo.push_back(base);
    plataformeo.push_back(base2);
    plataformeo.push_back(base3);
    base.actualTexture.setPosition(Vector2f{2000,360});
    base2.actualTexture.setPosition(Vector2f{2289,140});
    base3.actualTexture.setPosition(Vector2f{2354,345});
    plataformeo.push_back(base);
    plataformeo.push_back(base2);
    plataformeo.push_back(base3);
    base.actualTexture.setPosition(Vector2f{2468,123});
    base2.actualTexture.setPosition(Vector2f{2789,356});
    base3.actualTexture.setPosition(Vector2f{3054,405});
    plataformeo.push_back(base);
    plataformeo.push_back(base2);
    plataformeo.push_back(base3);


    base.actualTexture.setPosition(Vector2f{3235,321});
    base2.actualTexture.setPosition(Vector2f{3456,232});
    base3.actualTexture.setPosition(Vector2f{3568,125});
    plataformeo.push_back(base);
    plataformeo.push_back(base2);
    plataformeo.push_back(base3);
    base.actualTexture.setPosition(Vector2f{3689,240});
    base2.actualTexture.setPosition(Vector2f{3804,340});
    base3.actualTexture.setPosition(Vector2f{4000,145});
    plataformeo.push_back(base);
    plataformeo.push_back(base2);
    plataformeo.push_back(base3);
    base.actualTexture.setPosition(Vector2f{4200,150});
    base2.actualTexture.setPosition(Vector2f{4400,250});
    base3.actualTexture.setPosition(Vector2f{4600,350});
    plataformeo.push_back(base);
    plataformeo.push_back(base2);
    plataformeo.push_back(base3);
    base.actualTexture.setPosition(Vector2f{4768,123});
    base2.actualTexture.setPosition(Vector2f{4965,300});
    base3.actualTexture.setPosition(Vector2f{5124,200});
    plataformeo.push_back(base);
    plataformeo.push_back(base2);
    plataformeo.push_back(base3);

    base.actualTexture.setPosition(Vector2f{5200,123});
    base2.actualTexture.setPosition(Vector2f{5362,200});
    base3.actualTexture.setPosition(Vector2f{5500,147});
    plataformeo.push_back(base);
    plataformeo.push_back(base2);
    plataformeo.push_back(base3);
    base.actualTexture.setPosition(Vector2f{5678,365});
    base2.actualTexture.setPosition(Vector2f{5864,258});
    base3.actualTexture.setPosition(Vector2f{5978,369});
    plataformeo.push_back(base);
    plataformeo.push_back(base2);
    plataformeo.push_back(base3);
    base.actualTexture.setPosition(Vector2f{6100,365});
    base2.actualTexture.setPosition(Vector2f{6358,159});
    base3.actualTexture.setPosition(Vector2f{6578,176});
    plataformeo.push_back(base);
    plataformeo.push_back(base2);
    plataformeo.push_back(base3);
    
    
    vector<int>lista;
    
    for(int i=0;i<5;i++){
        otra:
        int random=rand()%plataformeo.size();
        for(int j=0;j<lista.size();i++){
            if(lista[i]==random)goto otra;
        }
        Volador* nuevoEnemigo= new Volador(Vector2f{plataformeo[random].actualTexture.getPosition().x+40,plataformeo[random].actualTexture.getPosition().y-70 });
        hongos.push_back(*nuevoEnemigo);

    }

    
    Barrera pared(Vector2f{5000,0});
    PisoLava lava(Vector2f{4500,450});
    lava.setExtention(300);
    obstaculos.push_back(pared);
    obstaculos.push_back(lava);

    pared.actualTexture.setPosition(Vector2f{5250,0});
    lava.actualTexture.setPosition(Vector2f{5000,450});
    lava.setExtention(2000);
    obstaculos.push_back(pared);
    obstaculos.push_back(lava);


    pared.actualTexture.setPosition(Vector2f{5600,0});
    obstaculos.push_back(pared);
    pared.actualTexture.setPosition(Vector2f{5864,0});
    obstaculos.push_back(pared);
    pared.actualTexture.setPosition(Vector2f{6000,0});
    obstaculos.push_back(pared);
    pared.actualTexture.setPosition(Vector2f{6200,0});
    obstaculos.push_back(pared);
    pared.actualTexture.setPosition(Vector2f{6400,0});
    obstaculos.push_back(pared);
    pared.actualTexture.setPosition(Vector2f{6600,0});
    obstaculos.push_back(pared);
    // pared.actualTexture.setPosition(Vector2f{5600,0});
    // obstaculos.push_back(pared);


    
    // for(int i=0;i<10;i++){
    //     float posicionx =(rand()% (i+1)*350)+500;
    //     float posiciony=(rand()&300)+100;
    //     int probabilidad=rand()&2;
    //     if(probabilidad==0){
    //         Enemigo* nuevoEnemigo= new Volador(Vector2f{posicionx+10,posiciony-70});
    //         hongos.push_back(*nuevoEnemigo);
    //         //delete nuevoEnemigo;
    //     }
    //     Plataforma* plataformaP=new Plataforma(Vector2f{posicionx,posiciony});
    //     plataformeo.push_back(*plataformaP);
    // }
    //hongos.push_back(lilith);

    Fondo atras;
    int x=0,y=0;

    int ultima=0;
    
    bool recargar=false;
    int dash=0;
   
    bool presion=false;
    
    bool si=false;
    Plataforma* tocando;

    SoundBuffer buffer;
    if (!buffer.loadFromFile("assets/principal.mp3"))
    {
        cout << "No funciona la musica" << endl;
    }
    Sound sound;
    sound.setBuffer(buffer);
    sound.play();


    adan.drawTo(window);
    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if(adan.boss==false){
                if(event.type==Event::KeyPressed){
                
                
                if(event.key.code==Keyboard::A ){
                    if(adan.tatekieto==false) x=-1;
                    adan.vista.x=-1;
                    ultima=adan.vista.x;
                    presion=true;
                    adan.actualTexture.setTexture(adan.espejo);
                    adan.actualTexture.setTextureRect(IntRect(18,17,13,17));
                    
                    
                    
                    
                }
                if(event.key.code==Keyboard::D){
                    if(adan.tatekieto==false)x=1;
                    adan.vista.x=1;
                    ultima=adan.vista.x;
                    presion=true;
                    adan.actualTexture.setTexture(adan.stmTexture);
                    adan.actualTexture.setTextureRect(IntRect(30,20,13,17));
                   
                    
            
                    
                    
                    
                }
                /// TAMPOCO ESTO, ES QUE NOS DA DOBLE SALTO
                if(event.key.code==Keyboard::Space  && adan.salto==true ){ // si presionas y puede saltar
                    
                  
                    adan.salto=false;
                                     
                }
                if(event.key.code==Keyboard::W){ /// tecla de comprobacion
                    adan.vista.y=-1;

                }
                if(event.key.code==Keyboard::S){ /// tecla de comprobacion
                    adan.vista.y=1;
                    

                }
                if(event.key.code==Keyboard::I){ /// tecla de comprobacion
                    //for(int i=0;i<hongos.size();i++) cout<<hongos[i].vida<<endl;
                    // cout<<atras.getA()<<endl;
                    // cout<<adan.boss<<endl;
                    // for(int i=0;i<hongos.size();i++){
                    //     cout<<adan.actualTexture.getPosition().x-hongos[i].actualTexture.getPosition().x<<endl;
                    // }
                    // for(int i=0;i<lucy.cuernitos.size();i++){
                    //     cout<<lucy.cuernitos[i].actualTexture.getPosition().x<<" "<< lucy.cuernitos[i].actualTexture.getPosition().y<<endl;
                    // }
                    cout<<atras.getA()<<" "<<adan.actualTexture.getPosition().y<<endl;
                    
                    //cout<<adan.getPosition().y<<endl;
                    //cout<<adan.vida<<" "<<serpiente.vida<<endl<<atras.getA();
                    // std::cout<<atras.getA()<<std::endl;
                    // std::cout<<adan.actualTexture.getPosition().x<<std::endl;
                    //std::cout<<adan.contRecarga<<std::endl;
                    //std::cout<<adan.pistola->municion<<std::endl;
                    // std::cout<<base.getPosition().x<<" "<<base.getPosition().y<<endl;
                    // std::cout<<adan.getPosition().x<<" "<<adan.getPosition().y<<endl;
                    // for(int i=0;i<adan.pistola->existentes.size();i++){
                        
                    //     //std::cout<<"disparo "<<i+1<<": "<<adan.pistola->existentes[i]->getPosition().x<<" "<<adan.pistola->existentes[i]->getPosition().x<< " direccion x:"<<adan.pistola->existentes[i]->getDireccion().x<<" direccion y:"<<adan.pistola->existentes[i]->getDireccion().y<<std::endl;
                    // }// modificalo para ver que esta pasando, por que no guarda el ultimo disparo, por que no detecta cual fue la ultima etc,

                }
                if(event.key.code==Keyboard::R){
                    recargar=true;
                }
                if(event.key.code==Keyboard::LShift){
                    adan.tatekieto=true;
                }
                if(event.key.code==Keyboard::Left){
                    adan.shot(adan.vista,ultima);
                }
                if(event.key.code==Keyboard::E){
                    if(adan.pistola!=nullptr)adan.pistola->especial(x,dash);
                }
                if(event.key.code==Keyboard::Q){ ///dropear arma--
                    //if(adan.pistola!=nullptr)adan.pistola->tirada=true;
                   
                }
                


                


            }else if(event.type==Event::KeyReleased){// para que no se queden haciendo algo infinitamente
                
                if(event.key.code == Keyboard::A) {
                    if(x==-1)x=0;
                    presion=false;
                    if(!event.key.code==Keyboard::W || !event.key.code==Keyboard::S)adan.vista.x=0; // esto hace que no se muevan si está parado, pero si no lo ponemos entonces no puede disparar para arriba
                }
                if( event.key.code == Keyboard::D ) {
                    if(x==1)x=0;
                    presion=false;
                    if(!event.key.code==Keyboard::W||!event.key.code==Keyboard::S)adan.vista.x=0;
                }
                //if(event.key.code == Keyboard::S) y=0;
                if(event.key.code==Keyboard::W ) adan.vista.y=0;
                if(event.key.code==Keyboard::S )adan.vista.y=0;
                if(event.key.code == Keyboard::LShift) adan.tatekieto=false;
                if(event.key.code == Keyboard::A && event.key.code == Keyboard::D && event.key.code==Keyboard::W && event.key.code==Keyboard::S) adan.vista.x=ultima; // no funciona
               
            }


            }
            
            
            
        }
        if(adan.boss==false){
            ///EFRA NO TOQUES ESTO 
        si=false;
        for(int i=0;i<plataformeo.size();i++){
            if(plataformeo[i].toca(adan)){
                si=true;
                
                tocando=&plataformeo[i];
            }

        }
        if(adan.actualTexture.getPosition().y<400 && adan.salto==true && !si){
            
            y=1;
           
        }else {
            if(!adan.salto){
                adan.saltar(y);
            }

            if(si && adan.salto){
                y=0;
                adan.contSalto=0;

            }else{
                if(si){
                    si=false;
                    
                    
                }
                
            }
                
            if(adan.actualTexture.getPosition().y==400 && adan.salto){
            
                y=0;
                adan.contSalto=0;
            }
        } 
            
         
        /// NADA DE ESTO

        if(recargar==true && adan.pistola!=nullptr){
            adan.recargar(recargar);
        }

        
        if(adan.pistola!=nullptr && adan.pistola->desplazar==true && dash<20){
            
            if(x==0)x=adan.vista.x;
            if(dash==0)x=x*3;
            dash++;
            
            cout<<x<<" "<<dash<<" "<<adan.pistola->desplazar<<endl;
            
        }else if(dash==20 && adan.pistola!=nullptr){ 
            if(adan.pistola!=nullptr)adan.pistola->desplazar=false;
            dash=0;
            cout<<adan.vista.x<<endl;

            if(presion==false){
                x=0;
            }else{
                x=adan.vista.x;
            }
            cout<<x<<endl;
        }
        adan.update(x,y,atras,plataformeo,hongos,obstaculos,lucy);
        for(int i=0;i<hongos.size();i++){
            if(!hongos[i].getEstado() && hongos[i].aparecer(&adan))hongos[i].disparo(adan,x,y);
        }
        
        
        atras.drawTo(window);
        if(!adan.muerto)adan.drawTo(window);
        if(adan.pistola!=nullptr)adan.pistola->drawTo(window);
        for(int i=0;i<hongos.size();i++){
            if(hongos[i].aparecer(&adan)){
                hongos[i].drawTo(window);
                hongos[i].pistola->drawTo(window);
            }
            
        }
        
        for(int i=0;i<plataformeo.size();i++)plataformeo[i].drawTo(window);
        

        
            for(int i=0;i<adan.pistola->existentes.size(); i-=-1){
                for(int j=0;j<hongos.size();j++){
                    adan.pistola->existentes[i]->trayectoria();
                    adan.pistola->existentes[i]->Impacto(hongos[j].actualTexture,hongos[j].vida,hongos[j].getEstado());
                    adan.pistola->existentes[i]->drawTo(window);
                }
                
            
            }
        
        for(int h=0;h<hongos.size();h++){
            for(int i=0;i<hongos[h].pistola->existentes.size();i-=-1){
                if(hongos[i].aparecer(&adan)){
                    hongos[h].pistola->existentes[i]->trayectoria();
                    hongos[h].pistola->existentes[i]->Impacto(adan.actualTexture,adan.vida,adan.muerto);
                
                    hongos[h].pistola->existentes[i]->drawTo(window);
                }
                
        }
        }
        
        for(int i=0;i<obstaculos.size();i++){
            obstaculos[i].desaparecer();
            obstaculos[i].golpe(adan);
            obstaculos[i].drawTo(window);
        }


        lucy.disparo();


        for(int i=0;i<lucy.cuernitos.size();i++){
            for(int j=0;j<lucy.cuernitos[i].existentes.size();j++){
                lucy.cuernitos[i].existentes[j]->trayectoria();
                lucy.cuernitos[i].existentes[j]->Impacto(adan.actualTexture,adan.vida,adan.muerto);
                lucy.cuernitos[i].existentes[j]->drawTo(window);
            }
        }
        for(int i=0;i<lucy.cuernitos.size();i++){
            lucy.cuernitos[i].drawTo(window);
        }
        lucy.drawTo(window);
        
        window.display();
        }
        if(adan.boss){
            
            window.clear();
            finalizar.fin(window);
            window.display();
            break;
        }
        if(adan.muerto){
            window.clear();
            
            break;
        }
    }


                        if(adan.boss){
                            readAndWriteNames(escribir,adan);
                        }
                        window.close();
                    }
                    if(x==2){
                         escribir=false;
                        readAndWriteNames(escribir,adan);
                        escribir=true;
                       
                    }
                    if(x==3){
                        window.close();
                    }
                }
            }
            window.clear();
            iniciador.interaccion(x);
            iniciador.drawTo(window);
            window.display();
        }
    }
    //Juego(window,adan);
    return 0;
}

/*while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if(adan.boss==false){
                if(event.type==Event::KeyPressed){
                
                
                if(event.key.code==Keyboard::A ){
                    if(adan.tatekieto==false) x=-1;
                    adan.vista.x=-1;
                    ultima=adan.vista.x;
                    presion=true;
                    adan.actualTexture.setTexture(adan.espejo);
                    adan.actualTexture.setTextureRect(IntRect(18,17,13,17));
                    
                    
                    
                    
                }
                if(event.key.code==Keyboard::D){
                    if(adan.tatekieto==false)x=1;
                    adan.vista.x=1;
                    ultima=adan.vista.x;
                    presion=true;
                    adan.actualTexture.setTexture(adan.stmTexture);
                    adan.actualTexture.setTextureRect(IntRect(30,20,13,17));
                   
                    
            
                    
                    
                    
                }
                /// TAMPOCO ESTO, ES QUE NOS DA DOBLE SALTO
                if(event.key.code==Keyboard::Space  && adan.salto==true ){ // si presionas y puede saltar
                    
                  
                    adan.salto=false;
                                     
                }
                if(event.key.code==Keyboard::W){ /// tecla de comprobacion
                    adan.vista.y=-1;

                }
                if(event.key.code==Keyboard::S){ /// tecla de comprobacion
                    adan.vista.y=1;
                    

                }
                if(event.key.code==Keyboard::I){ /// tecla de comprobacion
                    //for(int i=0;i<hongos.size();i++) cout<<hongos[i].vida<<endl;
                    // cout<<atras.getA()<<endl;
                    // cout<<adan.boss<<endl;
                    // for(int i=0;i<hongos.size();i++){
                    //     cout<<adan.actualTexture.getPosition().x-hongos[i].actualTexture.getPosition().x<<endl;
                    // }
                    // for(int i=0;i<lucy.cuernitos.size();i++){
                    //     cout<<lucy.cuernitos[i].actualTexture.getPosition().x<<" "<< lucy.cuernitos[i].actualTexture.getPosition().y<<endl;
                    // }
                    cout<<atras.getA()<<" "<<adan.actualTexture.getPosition().y<<endl;
                    
                    //cout<<adan.getPosition().y<<endl;
                    //cout<<adan.vida<<" "<<serpiente.vida<<endl<<atras.getA();
                    // std::cout<<atras.getA()<<std::endl;
                    // std::cout<<adan.actualTexture.getPosition().x<<std::endl;
                    //std::cout<<adan.contRecarga<<std::endl;
                    //std::cout<<adan.pistola->municion<<std::endl;
                    // std::cout<<base.getPosition().x<<" "<<base.getPosition().y<<endl;
                    // std::cout<<adan.getPosition().x<<" "<<adan.getPosition().y<<endl;
                    // for(int i=0;i<adan.pistola->existentes.size();i++){
                        
                    //     //std::cout<<"disparo "<<i+1<<": "<<adan.pistola->existentes[i]->getPosition().x<<" "<<adan.pistola->existentes[i]->getPosition().x<< " direccion x:"<<adan.pistola->existentes[i]->getDireccion().x<<" direccion y:"<<adan.pistola->existentes[i]->getDireccion().y<<std::endl;
                    // }// modificalo para ver que esta pasando, por que no guarda el ultimo disparo, por que no detecta cual fue la ultima etc,

                }
                if(event.key.code==Keyboard::R){
                    recargar=true;
                }
                if(event.key.code==Keyboard::LShift){
                    adan.tatekieto=true;
                }
                if(event.key.code==Keyboard::Left){
                    adan.shot(adan.vista,ultima);
                }
                if(event.key.code==Keyboard::E){
                    if(adan.pistola!=nullptr)adan.pistola->especial(x,dash);
                }
                if(event.key.code==Keyboard::Q){ ///dropear arma--
                    if(adan.pistola!=nullptr)adan.pistola->tirada=true;
                   
                }
                


                


            }else if(event.type==Event::KeyReleased){// para que no se queden haciendo algo infinitamente
                
                if(event.key.code == Keyboard::A) {
                    if(x==-1)x=0;
                    presion=false;
                    if(!event.key.code==Keyboard::W || !event.key.code==Keyboard::S)adan.vista.x=0; // esto hace que no se muevan si está parado, pero si no lo ponemos entonces no puede disparar para arriba
                }
                if( event.key.code == Keyboard::D ) {
                    if(x==1)x=0;
                    presion=false;
                    if(!event.key.code==Keyboard::W||!event.key.code==Keyboard::S)adan.vista.x=0;
                }
                //if(event.key.code == Keyboard::S) y=0;
                if(event.key.code==Keyboard::W ) adan.vista.y=0;
                if(event.key.code==Keyboard::S )adan.vista.y=0;
                if(event.key.code == Keyboard::LShift) adan.tatekieto=false;
                if(event.key.code == Keyboard::A && event.key.code == Keyboard::D && event.key.code==Keyboard::W && event.key.code==Keyboard::S) adan.vista.x=ultima; // no funciona
               
            }


            }
            
            
            
        }
        if(adan.boss==false){
            ///EFRA NO TOQUES ESTO 
        si=false;
        for(int i=0;i<plataformeo.size();i++){
            if(plataformeo[i].toca(adan)){
                si=true;
                
                tocando=&plataformeo[i];
            }

        }
        if(adan.actualTexture.getPosition().y<400 && adan.salto==true && !si){
            
            y=1;
           
        }else {
            if(!adan.salto){
                adan.saltar(y);
            }

            if(si && adan.salto){
                y=0;
                adan.contSalto=0;

            }else{
                if(si){
                    si=false;
                    
                    
                }
                
            }
                
            if(adan.actualTexture.getPosition().y==400 && adan.salto){
            
                y=0;
                adan.contSalto=0;
            }
        } 
            
         
        /// NADA DE ESTO

        if(recargar==true && adan.pistola!=nullptr){
            adan.recargar(recargar);
        }

        
        if(adan.pistola!=nullptr && adan.pistola->desplazar==true && dash<20){
            
            if(x==0)x=adan.vista.x;
            if(dash==0)x=x*3;
            dash++;
            
            cout<<x<<" "<<dash<<" "<<adan.pistola->desplazar<<endl;
            
        }else if(dash==20 && adan.pistola!=nullptr){ 
            if(adan.pistola!=nullptr)adan.pistola->desplazar=false;
            dash=0;
            cout<<adan.vista.x<<endl;

            if(presion==false){
                x=0;
            }else{
                x=adan.vista.x;
            }
            cout<<x<<endl;
        }
        adan.update(x,y,atras,plataformeo,hongos,obstaculos,lucy);
        for(int i=0;i<hongos.size();i++){
            if(!hongos[i].getEstado() && hongos[i].aparecer(&adan))hongos[i].disparo(adan,x,y);
        }
        
        
        atras.drawTo(window);
        if(!adan.muerto)adan.drawTo(window);
        if(adan.pistola!=nullptr)adan.pistola->drawTo(window);
        for(int i=0;i<hongos.size();i++){
            if(hongos[i].aparecer(&adan)){
                hongos[i].drawTo(window);
                hongos[i].pistola->drawTo(window);
            }
            
        }
        
        for(int i=0;i<plataformeo.size();i++)plataformeo[i].drawTo(window);
        

        
            for(int i=0;i<adan.pistola->existentes.size(); i-=-1){
                for(int j=0;j<hongos.size();j++){
                    adan.pistola->existentes[i]->trayectoria();
                    adan.pistola->existentes[i]->Impacto(hongos[j].actualTexture,hongos[j].vida,hongos[j].getEstado());
                    adan.pistola->existentes[i]->drawTo(window);
                }
                
            
            }
        
        for(int h=0;h<hongos.size();h++){
            for(int i=0;i<hongos[h].pistola->existentes.size();i-=-1){
                if(hongos[i].aparecer(&adan)){
                    hongos[h].pistola->existentes[i]->trayectoria();
                    hongos[h].pistola->existentes[i]->Impacto(adan.actualTexture,adan.vida,adan.muerto);
                
                    hongos[h].pistola->existentes[i]->drawTo(window);
                }
                
        }
        }
        
        for(int i=0;i<obstaculos.size();i++){
            obstaculos[i].desaparecer();
            obstaculos[i].golpe(adan);
            obstaculos[i].drawTo(window);
        }


        lucy.disparo();


        for(int i=0;i<lucy.cuernitos.size();i++){
            for(int j=0;j<lucy.cuernitos[i].existentes.size();j++){
                lucy.cuernitos[i].existentes[j]->trayectoria();
                lucy.cuernitos[i].existentes[j]->Impacto(adan.actualTexture,adan.vida,adan.muerto);
                lucy.cuernitos[i].existentes[j]->drawTo(window);
            }
        }
        for(int i=0;i<lucy.cuernitos.size();i++){
            lucy.cuernitos[i].drawTo(window);
        }
        lucy.drawTo(window);
        
        window.display();
        }
        if(adan.boss){
            window.setFramerateLimit(1);
            window.clear();
            finalizar.fin(window);
            window.display();
            return;
        }
    }
*/