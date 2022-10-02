import 'heap.js';
import { MinHeap, MaxHeap } from './heap';

export class PriorityQueue {
    constructor(arr = [], heap = 'min'){
        if (heap === 'min') {
            this.priority = new MinHeap(arr);
        }
        else if (heap === 'max') {
            this.priority = new MaxHeap(arr);
        }
        else {
            console.log('Keyword invalid. Failed to initialize'); // then throw error
        }
        this.pq = {};
    }

    enqueue(value, priority) {
        this.pq[priority] = value;
        this.priority.heapPush(priority);
    }

    dequeue() {
        return this.priority.heapPop();
    }

}