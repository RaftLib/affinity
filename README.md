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
setting the following options:
```bash
-DCUSTOM_NAMESPACE=True
-DAFFINITY_NAMESPACE=Name
```
