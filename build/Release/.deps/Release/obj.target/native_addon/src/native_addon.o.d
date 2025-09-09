cmd_Release/obj.target/native_addon/src/native_addon.o := c++ -o Release/obj.target/native_addon/src/native_addon.o ../src/native_addon.cpp '-DNODE_GYP_MODULE_NAME=native_addon' '-DUSING_UV_SHARED=1' '-DUSING_V8_SHARED=1' '-DV8_DEPRECATION_WARNINGS=1' '-D_GLIBCXX_USE_CXX11_ABI=1' '-D_DARWIN_USE_64_BIT_INODE=1' '-D_LARGEFILE_SOURCE' '-D_FILE_OFFSET_BITS=64' '-DOPENSSL_NO_PINSHARED' '-DOPENSSL_THREADS' '-DNAPI_DISABLE_CPP_EXCEPTIONS' '-DNAPI_VERSION=8' '-DBUILDING_NODE_EXTENSION' -I/Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node -I/Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/src -I/Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/deps/openssl/config -I/Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/deps/openssl/openssl/include -I/Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/deps/uv/include -I/Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/deps/zlib -I/Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/deps/v8/include -I/Users/gui_dev_18/Desktop/MY_EXAMPLE/electron-native-app/node_modules/node-addon-api -I/usr/local/include -I/opt/homebrew/include  -O3 -gdwarf-2 -fno-strict-aliasing -mmacosx-version-min=10.15 -arch x86_64 -Wall -Wendif-labels -W -Wno-unused-parameter -std=gnu++17 -stdlib=libc++ -fno-rtti -std=c++17 -stdlib=libc++ -MMD -MF ./Release/.deps/Release/obj.target/native_addon/src/native_addon.o.d.raw   -c
Release/obj.target/native_addon/src/native_addon.o: \
  ../src/native_addon.cpp \
  /Users/gui_dev_18/Desktop/MY_EXAMPLE/electron-native-app/node_modules/node-addon-api/napi.h \
  /Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/node_api.h \
  /Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/js_native_api.h \
  /Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/js_native_api_types.h \
  /Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/node_api_types.h \
  /Users/gui_dev_18/Desktop/MY_EXAMPLE/electron-native-app/node_modules/node-addon-api/napi-inl.h \
  /Users/gui_dev_18/Desktop/MY_EXAMPLE/electron-native-app/node_modules/node-addon-api/napi-inl.deprecated.h \
  /Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/openssl/md5.h \
  /Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/openssl/macros.h \
  /Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/openssl/opensslconf.h \
  /Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/openssl/configuration.h \
  /Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/openssl/./configuration_asm.h \
  /Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/openssl/././archs/darwin64-x86_64-cc/asm/include/openssl/configuration.h \
  /Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/openssl/opensslv.h \
  /Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/openssl/./opensslv_asm.h \
  /Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/openssl/././archs/darwin64-x86_64-cc/asm/include/openssl/opensslv.h \
  /Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/openssl/e_os2.h \
  /Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/openssl/sha.h
../src/native_addon.cpp:
/Users/gui_dev_18/Desktop/MY_EXAMPLE/electron-native-app/node_modules/node-addon-api/napi.h:
/Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/node_api.h:
/Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/js_native_api.h:
/Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/js_native_api_types.h:
/Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/node_api_types.h:
/Users/gui_dev_18/Desktop/MY_EXAMPLE/electron-native-app/node_modules/node-addon-api/napi-inl.h:
/Users/gui_dev_18/Desktop/MY_EXAMPLE/electron-native-app/node_modules/node-addon-api/napi-inl.deprecated.h:
/Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/openssl/md5.h:
/Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/openssl/macros.h:
/Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/openssl/opensslconf.h:
/Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/openssl/configuration.h:
/Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/openssl/./configuration_asm.h:
/Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/openssl/././archs/darwin64-x86_64-cc/asm/include/openssl/configuration.h:
/Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/openssl/opensslv.h:
/Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/openssl/./opensslv_asm.h:
/Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/openssl/././archs/darwin64-x86_64-cc/asm/include/openssl/opensslv.h:
/Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/openssl/e_os2.h:
/Users/gui_dev_18/Library/Caches/node-gyp/22.13.1/include/node/openssl/sha.h:
