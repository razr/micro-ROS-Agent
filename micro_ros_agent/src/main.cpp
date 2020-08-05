#include <uxr/agent/utils/CLI.hpp>
#include <uxr/agent/types/XRCETypes.hpp>
#include <uxr/agent/utils/Callbacks.hpp>
#include <csignal>

#include "graph_manager.hpp"

GraphManager::GraphManager * gm;


void on_create_callback(const dds::xrce::ObjectKind& kind, const eprosima::fastrtps::rtps::GUID_t& guid, void* data) {
    std::cout <<  "ObjectKind: " <<(int) kind << "\n";
    if (kind == dds::xrce::OBJK_PARTICIPANT){
        gm->add_participant(guid, data);
    }else if(kind == dds::xrce::OBJK_DATAWRITER){
        gm->add_datawriter(guid, data);
    }
  
}

int main(int argc, char** argv)
{   
    gm = new GraphManager::GraphManager();

    eprosima::uxr::UDPv4Agent agent_udp4(8888, eprosima::uxr::Middleware::Kind::FASTDDS);
    agent_udp4.set_verbose_level(2);

    auto * cb_a = on_create_callback;
    agent_udp4.add_oncreate_callback(cb_a);
    
    agent_udp4.start();

    while (true) { std::this_thread::sleep_for(std::chrono::seconds(1)); }

    return 0;
}