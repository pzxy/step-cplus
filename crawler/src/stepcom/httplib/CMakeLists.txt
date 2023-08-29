aux_source_directory(./src src)
add_library(httplib STATIC ${src})

target_link_libraries(httplib PRIVATE OpenSSL::SSL OpenSSL::Crypto)
