#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>

#include <iostream>
#include <sstream>
#include <string>

#include "protos/helloworld.grpc.pb.h"
#include "server/termcolor.hpp"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;
using helloworld::Greeter;
using helloworld::HelloReply;
using helloworld::HelloRequest;

class GreeterServiceImpl final : public Greeter::Service {
  Status SayHello(ServerContext* context, const HelloRequest* request, // NOLINT(misc-unused-parameters)
                  HelloReply* reply) override {
    std::ostringstream output;

    output << termcolor::colorize << "Hello, " << termcolor::bright_blue <<
        request->name() <<
        termcolor::reset << "!" << std::endl;
    reply->set_message(output.str());
    return Status::OK;
  }
};

void RunServer() {
  const std::string server_address("0.0.0.0:50051");
  GreeterServiceImpl service;

  grpc::EnableDefaultHealthCheckService(true);
  grpc::reflection::InitProtoReflectionServerBuilderPlugin();

  ServerBuilder builder;

  builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
  builder.RegisterService(&service);

  std::unique_ptr<Server> server(builder.BuildAndStart());

  std::cout << "Server listening on '" << server_address << "'" << std::endl;

  server->Wait();
}

int main(int argc, char* argv[]) { // NOLINT(misc-unused-parameters)
  RunServer();

  return 0;
}
