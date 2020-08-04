
#include "rosidl_runtime_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_cpp/message_type_support.hpp"

#include <rosidl_typesupport_fastrtps_cpp/identifier.hpp>
#include <rosidl_typesupport_fastrtps_cpp/message_type_support.h>

#include "rmw_dds_common/msg/participant_entities_info.hpp"

// #include <uxr/agent/utils/CLI.hpp>
// #include <uxr/agent/types/XRCETypes.hpp>
// #include <uxr/agent/utils/Callbacks.hpp>
// #include <csignal>

// #include "graph_manager.hpp"

// void printGUID(const dds::GUID_t& guid) {
//     std::cout <<  "GUID:\n\t entityId.entityKind: " << (int) guid.entityId().entityKind() << "\n";
//     std::cout <<  "\t entityId.m_entityKey: ";

//     for (size_t i = 0; i < 3; i++){
//         std::cout << (int) guid.entityId().entityKey()[i] << " ";
//     }

//     std::cout <<  "\n\t guidPrefix: ";

//     for (size_t i = 0; i < 12; i++){
//         std::cout << (int) guid.guidPrefix()[i] << " ";
//     }
//     std::cout <<  "\n";
// }

// void on_create_callback(const dds::xrce::ObjectKind& kind, const dds::GUID_t& guid) {
//   std::cout <<  "ObjectKind: " <<(int) kind << "\n";
//   printGUID(guid);
// }

int main(int argc, char** argv)
{
    // eprosima::uxr::UDPv4Agent agent_udp4(8888, eprosima::uxr::Middleware::Kind::FASTDDS);
    // agent_udp4.set_verbose_level(5);

    // auto * cb_a = on_create_callback;
    // agent_udp4.add_oncreate_callback(cb_a);
    
    // agent_udp4.start();

    // graphmanager::GraphManager * gm = new graphmanager::GraphManager();
    // while (true) { std::this_thread::sleep_for(std::chrono::seconds(1)); }
    const rosidl_message_type_support_t * rosidl_message_type_support_;
    const message_type_support_callbacks_t * message_type_support_callbacks_;

    rosidl_message_type_support_ = rosidl_typesupport_cpp::get_message_type_support_handle<rmw_dds_common::msg::ParticipantEntitiesInfo>();
    rosidl_message_type_support_ = get_message_typesupport_handle(
      rosidl_message_type_support_, "rosidl_typesupport_fastrtps_cpp");
    return 0;
}