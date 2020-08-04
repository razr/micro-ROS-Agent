#include <uxr/agent/utils/CLI.hpp>
#include <uxr/agent/types/XRCETypes.hpp>
#include <uxr/agent/utils/Callbacks.hpp>
#include <csignal>

#include "graph_manager.hpp"

void printGUID(const dds::GUID_t& guid) {
    std::cout <<  "GUID:\n\t entityId.entityKind: " << (int) guid.entityId().entityKind() << "\n";
    std::cout <<  "\t entityId.m_entityKey: ";

    for (size_t i = 0; i < 3; i++){
        std::cout << (int) guid.entityId().entityKey()[i] << " ";
    }

    std::cout <<  "\n\t guidPrefix: ";

    for (size_t i = 0; i < 12; i++){
        std::cout << (int) guid.guidPrefix()[i] << " ";
    }
    std::cout <<  "\n";
}

void on_create_callback(const dds::xrce::ObjectKind& kind, const dds::GUID_t& guid) {
  std::cout <<  "ObjectKind: " <<(int) kind << "\n";
  printGUID(guid);
}

int main(int argc, char** argv)
{
    eprosima::uxr::UDPv4Agent agent_udp4(8888, eprosima::uxr::Middleware::Kind::FASTDDS);
    agent_udp4.set_verbose_level(5);

    auto * cb_a = on_create_callback;
    agent_udp4.add_oncreate_callback(cb_a);
    
    agent_udp4.start();

    graphmanager::GraphManager * gm = new graphmanager::GraphManager();
    while (true) { std::this_thread::sleep_for(std::chrono::seconds(1)); }

    return 0;
}