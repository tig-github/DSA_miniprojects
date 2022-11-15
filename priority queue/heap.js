// const minHeapify = (arr) =>  {
//     console.log("not implemented");
// }

// const maxHeapify = (arr) =>  {
//     console.log("not implemented");
// }

export class MinHeap {
    constructor(arr = []) {
        this.heap = [];
        if (arr.length !== 0){
            this.heap = minHeapify(arr);
        }
    }

    peek() {
        return this.heap[0];
    }

    heapPush(key) {
        this.heap.push(key);
        let i = this.heap.length-1;
        if (this.heap[Math.floor(i/2)] > key) {
            let temp = this.heap[Math.floor(i/2)];
            this.heap[Math.floor(i/2)] = this.heap[i];
            this.heap[i] = temp;
        }
    }

    heapPop() {
        if (this.heap.length === 0)  {
            console.log("Cannot remove from an empty heap");
            return null;
        }
        let i = 0;
        let temp = this.heap[0];
        this.heap[0] = this.heap.pop();
        while (2*i < this.heap.length - 1 && (this.heap[i] > this.heap[2*i] || this.heap[i] > this.heap[2*i + 1])) {
            if ((2*i + 1 >= this.heap.length && this.heap[2*i] > this.heap[i]) || (this.heap[2*i] < this.heap[2*i + 1])) {
                let temp2 = this.heap[i];
                this.heap[i] = this.heap[2*i];
                this.heap[2*i] = temp2;
                i = i*2;
            }
            else {
                let temp2 = this.heap[i];
                this.heap[i] = this.heap[2*i + 1];
                this.heap[2*i + 1] = temp2; 
                i = i*2 + 1;
            }
        }
        return temp;
    }

    heapPushPop(key) {
        if (this.heap.length === 0)  {
            console.log("Cannot remove from an empty heap");
            return null;
        }
        let i = 0;
        let temp = this.heap[0];
        this.heap[0] = key;
        while (2*i < this.heap.length - 1 && (this.heap[i] > this.heap[2*i] || this.heap[i] > this.heap[2*i + 1])) {
            if ((2*i + 1 >= this.heap.length && this.heap[2*i] > this.heap[i]) || (this.heap[2*i] < this.heap[2*i + 1])) {
                let temp2 = this.heap[i];
                this.heap[i] = this.heap[2*i];
                this.heap[2*i] = temp2;
                i = i*2;
            }
            else {
                let temp2 = this.heap[i];
                this.heap[i] = this.heap[2*i + 1];
                this.heap[2*i + 1] = temp2; 
                i = i*2 + 1;
            }
        }
        return temp;
    }
}


export class MaxHeap {
    constructor(arr = []) {
        this.heap = []
        if (arr.length !== 0){
            this.heap = maxHeapify(arr);
        }
    }

    peek() {
        return this.heap[0];
    }

    heapPush(key) {
        this.heap.push(key)
        let i = this.heap.length-1;
        if (this.heap[Math.floor(i/2)] < key) {
            let temp = this.heap[Math.floor(i/2)];
            this.heap[Math.floor(i/2)] = this.heap[i];
            this.heap[i] = temp;
        }
    }

    heapPop() {
        if (this.heap.length === 0)  {
            console.log("Cannot remove from an empty heap");
            return null;
        }
        let i = 0;
        let temp = this.heap[0];
        this.heap[0] = this.heap.pop();
        while (2*i < this.heap.length - 1 && (this.heap[i] < this.heap[2*i] || this.heap[i] < this.heap[2*i + 1])) {
            if ((2*i + 1 >= this.heap.length && this.heap[2*i] < this.heap[i]) || (this.heap[2*i] > this.heap[2*i + 1])) {
                let temp2 = this.heap[i];
                this.heap[i] = this.heap[2*i];
                this.heap[2*i] = temp2;
                i = i*2;
            }
            else {
                let temp2 = this.heap[i];
                this.heap[i] = this.heap[2*i + 1];
                this.heap[2*i + 1] = temp2; 
                i = i*2 + 1;
            }
        }
        return temp;
    }

    heapPushPop(key) {
        if (this.heap.length === 0)  {
            console.log("Cannot remove from an empty heap");
            return null;
        }
        let i = 0;
        let temp = this.heap[0];
        this.heap[0] = key;
        while (2*i < this.heap.length - 1 && (this.heap[i] < this.heap[2*i] || this.heap[i] < this.heap[2*i + 1])) {
            if ((2*i + 1 >= this.heap.length && this.heap[2*i] < this.heap[i]) || (this.heap[2*i] > this.heap[2*i + 1])) {
                let temp2 = this.heap[i];
                this.heap[i] = this.heap[2*i];
                this.heap[2*i] = temp2;
                i = i*2;
            }
            else {
                let temp2 = this.heap[i];
                this.heap[i] = this.heap[2*i + 1];
                this.heap[2*i + 1] = temp2; 
                i = i*2 + 1;
            }
        }
        return temp;
    }

}