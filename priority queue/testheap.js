import { MinHeap } from './heap.js';

const canAdd = () => {
    let heap = new MinHeap();
    heap.heapPush(1);
    heap.heapPush(5);
    heap.heapPush(3);
    heap.heapPush(7);
    heap.heapPush(9);
    heap.heapPush(4);
    console.log(heap.heap);
};

canAdd();