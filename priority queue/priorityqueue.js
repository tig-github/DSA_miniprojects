//import { MinHeap, MaxHeap } from './heap.js';
Heap = require('heap.js');
export class PriorityQueue {
    constructor(heap = 'min'){
        if (heap === 'min') {
            this.priority = new MinHeap();
        }
        else if (heap === 'max') {
            this.priority = new MaxHeap();
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
        let last = this.priority.heapPop();
        let obj = this.pq[last];
        delete this.pq[last];
        return obj;
    }

}