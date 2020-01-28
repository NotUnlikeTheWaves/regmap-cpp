#include <climits>
#include <cstdint>

template<typename T, uint8_t _reg_size>
class SubTypeRegister {
    public:
        SubTypeRegister(T& reg, uint8_t offset)
            : reg(reg), offset(offset), mask(((1 << (_reg_size)) - 1) << offset) {

        }

        // Allows for register = int;
        void operator=(T val) {
            reg = (reg & ~mask) | ((val << offset) & mask);
        }

        // Allows for int = register; This is also called user-defined conversion.
        operator T() const {
            return (reg & mask) >> offset;
        }

    private:
        const T mask;
        T& reg;
        const uint8_t offset;
};

template<typename T, int _map_size>
class RegisterMap {
    public:
        RegisterMap() {};

        T& createRegister(int addr) {
            return map[addr];
        }

        template<unsigned int _reg_size>
        SubTypeRegister<T, _reg_size> createSubTypeRegister(int addr, int offset) {
            // Assert that we're not trying to hold anything bigger than what is currently in,
            // so no 24-bit subregisters in a 16 bit uint registermap.
            static_assert(sizeof(T)*CHAR_BIT >= _reg_size, "Cannot create a subRegister smaller than");
            return SubTypeRegister<T, _reg_size>(map[addr], offset);
        }

    private:
        T map[_map_size] = {};
};
