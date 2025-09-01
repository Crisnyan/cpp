#include "Serializer.hpp"

uintptr_t Serializer::serialize(Data *raw) {
		uintptr_t serialized = reinterpret_cast<uintptr_t>(raw);
		return (serialized);
}

Data *Serializer::deserialize(uintptr_t raw) {
		Data *deserialized = reinterpret_cast<Data *>(raw);
		return (deserialized);
}
