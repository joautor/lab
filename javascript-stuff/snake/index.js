// Snake movement directions
const LEFT  = 0;
const UP    = 1;
const DOWN  = 2;
const RIGHT = 3;

const gridNumTiles = 50;
const gridSize = Math.min(window.innerWidth, window.innerHeight);
const tileSize = gridSize / gridNumTiles;

// Set the canvas
const canvas = document.querySelector('canvas');
const c = canvas.getContext('2d');
canvas.width = gridSize;
canvas.height = gridSize;

let snake = null;
let food = null;
let foodEatenNum = 0;
let score = 0;
let level = 1;
let Obstacles = [];


class Position {

    constructor(x = 0, y = 0) {
        this.x = x;
        this.y = y;
    }
}

class Node {

    constructor(x, y) {
        this.x = x;
        this.y = y;
        this.prev = null;
        this.next = null;
    }
}

class DLinkedList {

    constructor(data = null) {

        this.head = data;
    }

    add(data) {

        // Assign new inserted data as the head
        let tempHead = this.head;
        if (tempHead != null) tempHead.prev = data;
        data.next = tempHead;
        data.prev = null;

        this.head = data;
    }

    getFirst() {

        return this.head;
    }

    getLast() {

        let lastNode = this.head;
        if (lastNode != null) {
            while (lastNode.next) {
                lastNode = lastNode.next;
            } 
        }
        return lastNode;
    }
}

class Snake {

    constructor(linkedList) {

        this.linkedList = linkedList;
        this.curDir = RIGHT; // Moving to the right by default;
    }

    isEat(food) {

        // Can we eat this food?
        let nextHeadPos = this.getNextHeadPosition();
        if ((food.x === nextHeadPos.x) && (food.y === nextHeadPos.y)) {
            this.linkedList.add(new Node(food.x, food.y)); // Create new node based on food location and add it to the list. The added node becomes the head.
            return true;
        }
        return false;
    }

    isSelfCollision() {

        let head = this.linkedList.getFirst();
        let node = head.next;
        while (node) {
            if ((head.x === node.x) && (head.y === node.y)) return true;
            node = node.next;
        }
        return false;
    }

    getNextHeadPosition() {

        let head = this.linkedList.getFirst();
        let x = head.x;
        let y = head.y;
    
        switch(this.curDir) {
            case LEFT:
                x  = (x - 1 + gridNumTiles) % gridNumTiles;
                break;
            case UP:
                y = (y - 1 + gridNumTiles) % gridNumTiles;
                break;
            case DOWN:
                y = (y + 1 + gridNumTiles) % gridNumTiles;;
                break;
            case RIGHT:
                x = (x + 1 + gridNumTiles) % gridNumTiles;
                break;
        }
        return new Position(x, y);
    }

    draw() {

        c.fillStyle = 'red'
        let node = this.linkedList.getFirst();
        while(node) {
            c.fillRect(node.x * tileSize, node.y * tileSize, tileSize, tileSize)
            node = node.next;
        }
    }

    update() {

        // Detach last node from the list
        let node = this.linkedList.getLast();
        node.prev.next = null;

        // Update node position based on current movement direction of the snake
        let nextPos = this.getNextHeadPosition();
        node.x = nextPos.x;
        node.y = nextPos.y;

        // Reattach the node to the front as the new head
        this.linkedList.add(node);

    }

    setMoveDir(newDir) {

        if (newDir === this.curDir) return;
        
        // Snake cannot move in the opposite direction
        if ((this.curDir === LEFT) && (newDir === RIGHT)) return;
        if ((this.curDir === UP) && (newDir === DOWN)) return;
        if ((this.curDir === DOWN) && (newDir === UP)) return;
        if ((this.curDir === RIGHT) && (newDir === LEFT)) return;

        this.curDir = newDir;
    }
}

class Food {

    constructor(x, y, value) {
        this.x = x;
        this.y = y;
        this.value = value;
    }

    draw() {
        c.fillStyle = 'blue';
        c.fillRect(this.x * tileSize, this.y * tileSize, tileSize, tileSize);
    }
}

class Obstacle {

    constructor(x, y) {
        this.x = x;
        this.y = y;
    }

    draw() {
        c.fillStyle = 'yellow';
        c.fillRect(this.x * tileSize, this.y * tileSize, tileSize, tileSize);
    }
}

function createSnake() {

    let linkedList = new DLinkedList();
    linkedList.add(new Node(1, 25));
    linkedList.add(new Node(2, 25));
    linkedList.add(new Node(3, 25));
    linkedList.add(new Node(4, 25));
    linkedList.add(new Node(5, 25));

    return new Snake(linkedList);
}

function createFood() {

    let x = Math.floor(Math.random() * gridNumTiles);
    let y = Math.floor(Math.random() * gridNumTiles);
    return new Food(x, y, 2 * level);
}

function createObstacles(level)
{
    if (level === 1) Obstacles = [];
    else if (level === 2) {
        Obstacles = [
            // Upper left
            new Obstacle(0, 0),
            new Obstacle(1, 0),
            new Obstacle(2, 0),
            new Obstacle(3, 0),
            new Obstacle(4, 0),
            new Obstacle(5, 0),
            new Obstacle(6, 0),
            new Obstacle(7, 0),
            new Obstacle(8, 0),
            new Obstacle(9, 0),
            new Obstacle(0, 1),
            new Obstacle(0, 2),
            new Obstacle(0, 3),
            new Obstacle(0, 4),
            new Obstacle(0, 5),
            new Obstacle(0, 6),
            new Obstacle(0, 7),
            new Obstacle(0, 8),
            new Obstacle(0, 9),

            // Upper right
            new Obstacle(40, 0),
            new Obstacle(41, 0),
            new Obstacle(42, 0),
            new Obstacle(43, 0),
            new Obstacle(44, 0),
            new Obstacle(45, 0),
            new Obstacle(46, 0),
            new Obstacle(47, 0),
            new Obstacle(48, 0),
            new Obstacle(49, 0),
            new Obstacle(49, 1),
            new Obstacle(49, 2),
            new Obstacle(49, 3),
            new Obstacle(49, 4),
            new Obstacle(49, 5),
            new Obstacle(49, 6),
            new Obstacle(49, 7),
            new Obstacle(49, 8),
            new Obstacle(49, 9),

            // Lower right
            new Obstacle(49, 40),
            new Obstacle(49, 41),
            new Obstacle(49, 42),
            new Obstacle(49, 43),
            new Obstacle(49, 44),
            new Obstacle(49, 45),
            new Obstacle(49, 46),
            new Obstacle(49, 47),
            new Obstacle(49, 48),
            new Obstacle(49, 49),
            new Obstacle(48, 49),
            new Obstacle(47, 49),
            new Obstacle(46, 49),
            new Obstacle(45, 49),
            new Obstacle(44, 49),
            new Obstacle(43, 49),
            new Obstacle(42, 49),
            new Obstacle(41, 49),
            new Obstacle(40, 49),

            // Lower left
            new Obstacle(0, 40),
            new Obstacle(0, 41),
            new Obstacle(0, 42),
            new Obstacle(0, 43),
            new Obstacle(0, 44),
            new Obstacle(0, 45),
            new Obstacle(0, 46),
            new Obstacle(0, 47),
            new Obstacle(0, 48),
            new Obstacle(0, 49),
            new Obstacle(1, 49),
            new Obstacle(2, 49),
            new Obstacle(3, 49),
            new Obstacle(4, 49),
            new Obstacle(5, 49),
            new Obstacle(6, 49),
            new Obstacle(7, 49),
            new Obstacle(8, 49),
            new Obstacle(9, 49),

            // Center parallel lines
            new Obstacle(15, 20),
            new Obstacle(16, 20),
            new Obstacle(17, 20),
            new Obstacle(18, 20),
            new Obstacle(19, 20),
            new Obstacle(20, 20),
            new Obstacle(21, 20),
            new Obstacle(22, 20),
            new Obstacle(23, 20),
            new Obstacle(24, 20),
            new Obstacle(25, 20),
            new Obstacle(26, 20),
            new Obstacle(27, 20),
            new Obstacle(28, 20),
            new Obstacle(29, 20),
            new Obstacle(30, 20),
            new Obstacle(31, 20),
            new Obstacle(32, 20),
            new Obstacle(33, 20),
            new Obstacle(34, 20),

            new Obstacle(15, 30),
            new Obstacle(16, 30),
            new Obstacle(17, 30),
            new Obstacle(18, 30),
            new Obstacle(19, 30),
            new Obstacle(20, 30),
            new Obstacle(21, 30),
            new Obstacle(22, 30),
            new Obstacle(23, 30),
            new Obstacle(24, 30),
            new Obstacle(25, 30),
            new Obstacle(26, 30),
            new Obstacle(27, 30),
            new Obstacle(28, 30),
            new Obstacle(29, 30),
            new Obstacle(30, 30),
            new Obstacle(31, 30),
            new Obstacle(32, 30),
            new Obstacle(33, 30),
            new Obstacle(34, 30)
        ];
    }
}

function keyDownCallBack(event) {

    switch (event.keyCode) {
        case 37:
            console.log('left');
            snake.setMoveDir(LEFT);
            break;

        case 38:
            console.log('up');
            snake.setMoveDir(UP);
            break;

        case 40:
            console.log('down')
            snake.setMoveDir(DOWN);
            break;

        case 39:
            console.log('right')
            snake.setMoveDir(RIGHT);
            break;
    }
}

function init() {
    snake = createSnake();
    food = createFood();
    score = 0;
    foodEatenNum = 0;
    level = 1;
    createObstacles(level);
}

function reset() {
    init();
}

function animate() {
    requestAnimationFrame(animate);

    c.fillStyle = 'black';
    c.fillRect(0, 0, canvas.width, canvas.height);

    Obstacles.forEach((obstacle) => { obstacle.draw(); });
    food.draw();
    snake.draw();

    // Draw score text
    c.font = "12px Arial";
    c.fillStyle = "white";
    c.filleAlign = "center";
    c.fillText("score: " + score, 25, 25);

    // Lose conditions
    let isObstacleCollision = false;
    Obstacles.forEach((obstacle) => {
        let snakeHead = snake.linkedList.getFirst();
        if ((obstacle.x == snakeHead.x) && (obstacle.y === snakeHead.y)) {
            isObstacleCollision = true;
            return;
        }
    });
    if (isObstacleCollision || snake.isSelfCollision()) {
        window.alert("you lose!");
        reset();
    }

    if (snake.isEat(food)) {
        score += food.value;
        foodEatenNum++;
        food = createFood();
    } else { // Normal movement
        snake.update();
    }

    if (foodEatenNum === 10) {
        foodEateNum = 0;
        level++;
        createObstacles(level);
        snake = createSnake();
        food = createFood();
    }

}


init();
animate();
window.addEventListener('keydown', keyDownCallBack);


