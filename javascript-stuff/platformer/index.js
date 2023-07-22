const canvas = document.querySelector('canvas')
const c = canvas.getContext('2d')
canvas.width = 1024 // window.innerWidth     // note: window can be ommited
canvas.height = 576 // window.innerHeight
const gravity = 1.5

function createImage(filePath, width, height) {
    const image = new Image(width, height);
    image.src = filePath
    return image
}

class Player {
    constructor() {
        this.position =  {
            x: 100,
            y: 100
        }
        this.velocity = {
            x: 0,
            y: 0
        }
        this.width = 30
        this.height = 60

        this.speed = 7
        this.image = createImage('img/ninja_idle.png', 30, 60)
        this.frameIndex = 0 // What frame are we currently on?
        this.sprites = {
            stand: {
                right: createImage('img/ninja_idle.png', 30, 60),
                left: createImage('img/ninja_idle_left.png', 30, 60),
                cropWidth: 234,
                cropHeight: 441
            },
            run: {
                right: createImage('img/ninja_run_right.png', 46, 60),
                left: createImage('img/ninja_run_left.png', 46, 60),
                cropWidth: 365,
                cropHeight: 460
            }
        }
        this.currentSprite = this.sprites.stand.right
        this.currentCropWidth = this.sprites.stand.cropWidth
        this.currentCropHeight = this.sprites.stand.cropHeight
    }

    standRight() {
        this.currentSprite = this.sprites.stand.right
        this.currentCropWidth = this.sprites.stand.cropWidth
        this.width = this.currentSprite.width
    }

    standLeft() {
        this.currentSprite = this.sprites.stand.left
        this.currentCropWidth = this.sprites.stand.cropWidth
        this.width = this.currentSprite.width
    }

    runRight() {
        this.currentSprite = this.sprites.run.right
        this.currentCropWidth = this.sprites.run.cropWidth
        this.width = this.currentSprite.width
    }

    runLeft() {
        this.currentSprite = this.sprites.run.left
        this.currentCropWidth = this.sprites.run.cropWidth
        this.width = this.currentSprite.width
    }

    draw() {
        /*c.fillStyle = 'red'
        c.fillRect(this.position.x, this.position.y, this.width, this.height)
        */
        c.drawImage(
            this.currentSprite,
            this.currentCropWidth * this.frameIndex,
            0,
            this.currentCropWidth,
            this.currentCropHeight,
            this.position.x,
            this.position.y,
            this.width,
            this.height
        )
    }

    update() {
        this.frameIndex++
        if (this.frameIndex >= 10) this.frameIndex = 0

        this.draw()
        this.position.y += this.velocity.y
        this.position.x += this.velocity.x

        if ((this.position.y + this.height + this.velocity.y) <= canvas.height) {
            this.velocity.y += gravity
        }/* else {
            this.velocity.y = 0 // Stop player from falling
        }*/
    }
}

class Platform {
    constructor({ x, y, image}) {
        this.position = {
            x: x,
            y: y
        }
        this.image = image
        this.width = image.width
        this.height = image.height

    }
    draw() {
        /*
        c.fillStyle = 'blue'
        c.fillRect(this.position.x, this.position.y, this.width, this.height)
        */
        c.drawImage(this.image, this.position.x, this.position.y)
    }
}

class GenericObject {
    constructor({ x, y, image, relativeSpeed }) {
        this.position = {
            x: x,
            y: y
        }
        this.image = image
        this.width = image.width
        this.height = image.height
        this.relativeSpeed = relativeSpeed
    }
    draw() {
        c.drawImage(this.image, this.position.x, this.position.y, this.width, this.height)
    }
}

let platformImg
let backgroundImg
let superBackgroundImg
let player = new Player()
let platforms = []
let genericObjects = []
let keys = {}       // Monitor the keys being pressed
let scrollOffset = 0


function init() {
    platformImg = createImage('img/ninja_platform.png', 200, 20)
    backgroundImg = createImage('img/ninja_foreground_transparent.png', 3044, 600)
    superBackgroundImg = createImage('img/ninja_superbackground.png', 3044, 600)
    player = new Player()
    platforms = [
        new Platform({ x: platformImg.width * 0, y: 510, image: platformImg }),
        new Platform({ x: platformImg.width * 1, y: 510, image: platformImg }),
        new Platform({ x: platformImg.width * 2, y: 510, image: platformImg }),

        new Platform({ x: platformImg.width * 4, y: 510, image: platformImg }),
        new Platform({ x: platformImg.width * 5, y: 510, image: platformImg }),

        new Platform({ x: platformImg.width * 7, y: 510, image: platformImg }),
        new Platform({ x: platformImg.width * 9, y: 510, image: platformImg }),
        new Platform({ x: platformImg.width * 10, y: 390, image: platformImg }),
        new Platform({ x: platformImg.width * 10, y: 510, image: platformImg }),
        new Platform({ x: platformImg.width * 12.2, y: 510, image: platformImg }),
        new Platform({ x: platformImg.width * 13, y: 510, image: platformImg }),
        new Platform({ x: platformImg.width * 14, y: 510, image: platformImg }),
        new Platform({ x: platformImg.width * 15, y: 510, image: platformImg }),
        new Platform({ x: platformImg.width * 16, y: 510, image: platformImg }),
        new Platform({ x: platformImg.width * 17, y: 510, image: platformImg }),
        new Platform({ x: platformImg.width * 18, y: 510, image: platformImg }),
        new Platform({ x: platformImg.width * 19, y: 510, image: platformImg }),
        new Platform({ x: platformImg.width * 20, y: 510, image: platformImg }),
        new Platform({ x: platformImg.width * 21, y: 510, image: platformImg }),
        new Platform({ x: platformImg.width * 22, y: 510, image: platformImg }),
        new Platform({ x: platformImg.width * 23, y: 510, image: platformImg }),
        new Platform({ x: platformImg.width * 24, y: 510, image: platformImg }),
        new Platform({ x: platformImg.width * 25, y: 510, image: platformImg }),
        new Platform({ x: platformImg.width * 26, y: 510, image: platformImg }),
        new Platform({ x: platformImg.width * 27, y: 510, image: platformImg }),
    ]

    genericObjects = [
        new GenericObject({ x: -300, y: 0, image: superBackgroundImg, relativeSpeed: 0.10 }),
        new GenericObject({ x: -150, y: 0, image: backgroundImg, relativeSpeed: 0.33 }),
    ]

    keys = { 
        right: { pressed: false },
        left: { pressed: false },
        up: { pressed: false },
        down: { pressed: false }
    }

    scrollOffset = 0
}

function reset() {
    init()
}


function animate() {
    requestAnimationFrame(animate)
    // console.log("animating");
    // c.clearRect(0, 0, canvas.width, canvas.height)
    c.fillStyle = 'white'
    c.fillRect(0, 0, canvas.width, canvas.height)
    
    genericObjects.forEach(genericObject => {
        genericObject.draw()
    })

    platforms.forEach(platform => {
        platform.draw()
    })

    player.update()

    if (keys.right.pressed && player.position.x < 400) {
        player.velocity.x = player.speed
    } else if ((keys.left.pressed && player.position.x > 100) ||
               (keys.left.pressed && scrollOffset === 0 && player.position.x > 0)
    ) {
        player.velocity.x = -player.speed
    } else {
        player.velocity.x = 0

        // Scroll the platforms, generic objects
        if (keys.right.pressed) {
            scrollOffset += player.speed
            platforms.forEach(platform => {
                platform.position.x -= player.speed
            })
            genericObjects.forEach(genericObject => {
                genericObject.position.x -= (player.speed * genericObject.relativeSpeed)
            })
        } else if (keys.left.pressed && scrollOffset > 0) {
            scrollOffset -= player.speed
            platforms.forEach(platform => {
                platform.position.x += player.speed
            })
            genericObjects.forEach(genericObject => {
                genericObject.position.x += (player.speed * genericObject.relativeSpeed)
            })
        }
    }

    // Collision detection
    platforms.forEach(platform => {
        if (((player.position.y + player.height) <= platform.position.y) &&                         // y-axis
            ((player.position.y + player.height + player.velocity.y) >= platform.position.y) &&    // y-axis
            ((player.position.x + player.width) >= platform.position.x) &&                         // x-axis
            (player.position.x <= (platform.position.x + platform.width))                          // x-axis
            ) {
            player.velocity.y = 0
        }
    })

    // Win condition
    lastPlatform = platforms[platforms.length - 1]
    //console.log(lastPlatform)
    if (player.position.x > lastPlatform.position.x) {
        console.log("You win!")
        window.alert("You win!")
        reset()
    }

    // Lose condition
    if (player.position.y > canvas.height) {
        console.log("You lose!")
        reset()
    }

}

init()
animate()

window.addEventListener('keydown', (event) => {

    switch (event.keyCode) {
        case 65:
            console.log('left')
            keys.left.pressed = true
            player.runLeft()
            break

        case 83:
            console.log('down')
            break;

        case 68:
            console.log('right')
            keys.right.pressed = true
            player.runRight()
            break;

        case 87:
            console.log('up')
            if (!keys.up.pressed) {
                player.velocity.y -= 20 
                keys.up.pressed = true
            }
            break;
    }
})

window.addEventListener('keyup', (event) => {

    switch (event.keyCode) {
        case 65:
            console.log('left')
            keys.left.pressed = false
            player.standLeft()
            break

        case 83:
            console.log('down')
            keys.down.pressed = false
            break;

        case 68:
            console.log('right')
            keys.right.pressed = false
            player.standRight()
            break

        case 87:
            console.log('up')
            keys.up.pressed = false
            break
    }
})
