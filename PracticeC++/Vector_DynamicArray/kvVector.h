#include <memory>
#ifndef PRACTICE_CPP_KVARRAY_H
#define PRACTICE_CPP_KVARRAY_H

namespace kv {

static const int kMinCapacity = 16;
static const int kGrowthFactor = 2;
static const int kShrinkFactor = 16;


class kvVector {
    public:
        kvVector(int capacity);
        kvVector(const kvVector &other) = default;

        ~kvVector();

        int GetSize() const;
        bool isEmpty() const;

        int GetCapacity() const;

        void DebugString() const;

        void Push(int value);

        int GetValueAt(int index) const;

        int Pop();

        void Insert(int index, int value);

        void Prepend(int value);

        void Delete(int index);

        void Remove(int value);

        int Find(int value) const;

    private:
        int capacity_{kMinCapacity};

        int size_{0};

        std::unique_ptr<int[]> data_;

        int DetermineCapacity(int capacity) const;

        void ResizeForSize(int candidate_size);

        void IncreaseSize();

        void DecreaseSize();
};
}

#endif //PRACTICE_CPP_KVARRAY_H