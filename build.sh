cmake --build build -j$(sysctl -n hw.logicalcpu) --target $1
