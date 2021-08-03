# MICROBYTE

## microbyte_stm32f407

Deploy source code and generate build system files:
```
python platform/microbyte-platform.py --verbose deploy --target=microbyte_stm32f407 generate
```

Build the project:
```
cd __microbyte_stm32f407
mkdir build && cd build
cmake .. -G "Unix Makefiles" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_TOOLCHAIN_FILE=./../platform/SDK/microbyte_stm32f407/ARMGCC.cmake
make
```
