/*
    O CABECALHO!!!

    Arquivo com o noh inscrito no topico "nomeDoTopico" que printa na
    tela a mensagem recebida.

    Autor: PeixePerseguidor
*/

#include <ros/ros.h>
#include <std_msgs/String.h>

void receberMensagem(const std_msgs::String& msg) {
    // ROS_INFO -> Mesma coisa que o Serial.print() do Arduino
    // %s é substituido pelo msg.data.c_str()
    ROS_INFO("Mensagem recebida : %s", msg.data.c_str());
}

int main(int argc, char** argv) {  // int main padrão do C
    // Inicia o ros -> "meu_no" como nome do noh
    ros::init(argc, argv, "meu_noh");

    // Cria o objeto tratador do noh
    ros::NodeHandle noh;

    // Cria o objeto que trata o inscrito
    // Os parâmetros são: nome do topico, buffer e callback (função executada ao receber uma mensagem)
    ros::Subscriber inscrito = noh.subscribe("nomeDoTopico", 1000, receberMensagem);

    // Cuida da comunicação com o ROS
    ros::spin();

    // Retorna 0 padrão do C
    return 0;
}
