const heapify = (arr) =>  {
    console.log("not implemented");
}

export class MinHeap {
    constructor(arr = []) {
        this.heap = []
        if (arr.length !== 0){
            this.heap = heapify(arr);
        }
    }

    peek() {
        return this.heap[0];
    }

    heapPush(key) {
        this.heap.push(key)
        let i = this.heap.length-1;
        if (this.heap[Math.floor(i/2)] > key) {
            let temp = this.heap[Math.floor(i/2)];
            this.heap[Math.floor(i/2)] = this.heap[i];
            this.heap[i] = temp;
        }

    }

    heapPop() {
        let i = this.heap.length-1;
        let temp = this.heap[i];
        this.heap.pop();        
    }

    heapPushPop(key) {

    }

}