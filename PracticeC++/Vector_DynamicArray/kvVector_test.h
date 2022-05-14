#ifndef PROJECT_KVVECTOR_TEST_H
#define PROJECT_KVVECTOR_TEST_H

namespace kv {

    class kvVectorTest{
        public:
            void RunTests() const;
            void TestSize() const;
            // Test increases and decreases in capacity based on number of items stored
            void TestCapacity() const;
            void TestIsEmpty() const;
            void TestGetValueAt() const;
            void TestPop() const;
            void TestInsert() const;
            void TestDelete() const;
            void TestRemove() const;
            void TestFind() const;
            int Passing() const;
    };

}

#endif //PROJECT_KVVECTOR_TEST_H