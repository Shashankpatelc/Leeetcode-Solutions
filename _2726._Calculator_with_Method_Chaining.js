class Calculator {

    constructor(value) {
        this.value = value
        this.error = 0
    }

    add(value) {
        this.value += value
        return this
    }

    subtract(value) {
        this.value -= value
        return this
    }

    multiply(value) {
        this.value *= value
        return this
    }

    divide(value) {
        if (value === 0) {
            this.error = "Division by zero is not allowed"
        } else {
            this.value /= value
        }
        return this
    }

    power(value) {
        this.value = Math.pow(this.value, value)
        return this
    }

    getResult() {
        if (this.error) {
            return this.error
        }
        return this.value
    }
}