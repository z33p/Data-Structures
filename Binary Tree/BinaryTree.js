function Node(data, left = null, right = null) {
    this.data = data;
    this.left = left;
    this.right = right;

    this.insert = (data) => {

        if (data < this.data) {
            if (this.left == null) {
                this.left = new Node(data);

            } else {
                this.left.insert(data);

            }

        } else if (data > this.data) {
            if (this.right == null) {
                this.right = new Node(data);

            } else {
                this.right.insert(data);
            }
        }
    }


    this.search = (data) => {

        if (data === this.data) {
            return this;

        } else if (data < this.data) {
            if (this.left == null) {
                return null;

            } else {
                return this.left.search(data);
            }

        } else if (this.right == null) {
            return null;

        } else {
            return this.right.search(data);
        }
    }

    this.sorting = () => {
        if (this.left != null) {
            this.left.sorting();

        }

        console.log(this.data);

        if (this.right != null) {
            this.right.sorting();

        }
    }
}


root = new Node(17);
for (let index = 0; index < 25; index++) {
    root.insert(Math.floor(Math.random() * 50));
}

// console.log(root);
// console.log(root.search(33));
root.sorting();