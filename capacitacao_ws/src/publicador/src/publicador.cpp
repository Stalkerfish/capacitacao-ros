/*
    publicador.cpp --> sera um noh publicador

    Autor: PeixePerseguidor
    Autor: EquipeAtlas 22.1
*/

#include <ros/ros.h>          // incluindo biblioteca do ROS
#include <std_msgs/String.h>  // incluindo tipo de mensagem que sera utilizada nesse publicador

#define FREQUENCIA 10

int main(int argc, char **argv) {           // int main padraozao do c++
    ros::init(argc, argv, "noPublicador");  // incia o ROS, criando o noh

    ros::NodeHandle tratadorDoNoh;  // objeto "tratador" do noh = aquele que cuida do noh

    /*
     -------Criar o noh como publicador--------
     -Chamo o tratador do no para avisar("advertise") que o no dele eh um publicador.
     -Tambem falo o tipo de msg que ele vai publicar (estamos usando a string do "standard")
       obs: standard eh um grupo de "tipos padroes" de mensagens
     -O primeiro parametro de advertise eh o nome do topico e o segundo eh o tamanho do buffer
     -O valor do buffer representa a quantidade de msgs que o topico suporta.
     -A partir de 1000 os topicos mais antigos sao descartados para a entrada de novos
    */
    ros::Publisher tratadorDoPublicador = tratadorDoNoh.advertise<std_msgs::String>("nomeDoTopico", 1000);

    ros::Rate frequencia(FREQUENCIA);  // manda e remanda a mensagem com uma determinada frequencia

    // ros::ok() = True se ta tudo beleza
    while (ros::ok()) {
        std_msgs::String mensagemASerEnviada;  // Objeto (instancia) com a mensagem
        mensagemASerEnviada.data = "tudo em pt-br fodassi";

        tratadorDoPublicador.publish(mensagemASerEnviada);  // Envia a mensagem

        ros::spinOnce();  // loop do ros dentro do while que ta sempre true, mensagens infinitas
        ROS_INFO("VASCO");
        frequencia.sleep();  // delay igual do arduino
    }

    return 0;  // Retorna 0 padraozao do c++
}
// Sou Libre? Yes, you are!
// #abaixoaotratador
//#VASCO 3x0 FLAMENGO
