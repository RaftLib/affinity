# Affinity
* Pulled out raftlib core affinity functions to 
try to make more modular. This piece looks like 
it should be tested in isolation. 
* To build
```bash
cmake <path to affinity> -Wno-dev -CMAKE_BUILD_TYPE=[Release/Debug] -GNinja
ninja
ninja test
```
* You can inject your own namespace if you'd like by
setting the following options, also include the moduleflags.cmake
file at the global level so that CFLAGS prop through all files:
```bash
-DAFFINITY_CUSTOM_NAMESPACE=YES
-DAFFINITY_NAMESPACE=<Name>
```
* test cases only test functionality at the moment, 
need to add test cases for perf as well and more 
corner cases. 

## NOTE
* Currently  only sets affinity for Linux, 
will assign others to do Win/Mac at some point. 
