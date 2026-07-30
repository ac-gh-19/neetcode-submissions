class MinStack {
    constructor() {
        this.minStack = [];
        this.minValue = [];
        this.currMinValue = Number.MAX_VALUE;
    }

    push(val) {
        if (val < this.currMinValue) {
            this.currMinValue = val;
        }
        this.minStack.push(val);
        this.minValue.push(this.currMinValue);
    }

    pop() {
        if (this.minStack.length === 0) return;

        this.minStack.pop();
        this.minValue.pop();

        if (this.minValue.length === 0) {
            this.currMinValue = Number.MAX_VALUE;
        } else {
            this.currMinValue = this.minValue[this.minValue.length - 1];
        }
    }

    top() {
        if (this.minStack.length === 0) return undefined;
        return this.minStack[this.minStack.length - 1];
    }

    getMin() {
        return this.minStack.length === 0 ? undefined : this.currMinValue;
    }
}

