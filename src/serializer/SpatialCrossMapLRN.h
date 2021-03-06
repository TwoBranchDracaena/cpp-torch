#pragma once
#include "../../include/nn/SpatialCrossMapLRN.h"


namespace cpptorch
{
    namespace serializer
    {
        template<typename T, GPUFlag F>
        class SpatialCrossMapLRN : public nn::SpatialCrossMapLRN<T, F>
        {
        public:
            void unserialize(const object_torch *obj, object_reader<T, F> *mb)
            {
                const object_table *obj_tbl = obj->data_->to_table();
                this->size_ = *obj_tbl->get("size");
                this->alpha_ = *obj_tbl->get("alpha");
                this->beta_ = *obj_tbl->get("beta");
                this->k_ = *obj_tbl->get("k");
            }
        };
    }
}
