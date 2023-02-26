using System;
using System.Drawing;
using System.Windows.Forms;

namespace CarRacing
{
    public partial class MainForm : Form
    {
        // Console window size
        const int WIDTH = 400;
        const int HEIGHT = 600;

        // Car dimensions
        const int CAR_WIDTH = 40;
        const int CAR_HEIGHT = 80;

        // Car position and speed
        int carX = WIDTH / 2 - CAR_WIDTH / 2;
        int carY = HEIGHT - CAR_HEIGHT - 50;
        int carSpeed = 10;

        // Obstacle position and speed
        int obstacleX = 0;
        int obstacleY = 0;
        int obstacleSpeed = 10;

        // Score
        int score = 0;

        // Random number generator
        Random rand = new Random();

        public MainForm()
        {
            InitializeComponent();

            // Set form size
            this.ClientSize = new Size(WIDTH, HEIGHT);

            // Start the game loop
            gameTimer.Start();
        }

        private void gameTimer_Tick(object sender, EventArgs e)
        {
            // Move the car
            if (Input.Left)
            {
                carX -= carSpeed;
            }
            else if (Input.Right)
            {
                carX += carSpeed;
            }

            // Move the obstacle
            obstacleY += obstacleSpeed;
            if (obstacleY >= HEIGHT)
            {
                obstacleX = rand.Next(0, WIDTH - 100);
                obstacleY = 0;
                score++;
            }

            // Check for collision
            if (obstacleY + 100 >= carY && obstacleY <= carY + CAR_HEIGHT && obstacleX + 100 >= carX && obstacleX <= carX + CAR_WIDTH)
            {
                // Collision detected, end the game
                gameTimer.Stop();
                MessageBox.Show($"Game over! Your score was {score}.", "Car Racing", MessageBoxButtons.OK, MessageBoxIcon.Information);
                this.Close();
            }

            // Redraw the screen
            this.Invalidate();
        }

        private void MainForm_Paint(object sender, PaintEventArgs e)
        {
            // Draw the background
            e.Graphics.FillRectangle(Brushes.White, 0, 0, WIDTH, HEIGHT);

            // Draw the car
            e.Graphics.FillRectangle(Brushes.Blue, carX, carY, CAR_WIDTH, CAR_HEIGHT);

            // Draw the obstacle
            e.Graphics.FillRectangle(Brushes.Red, obstacleX, obstacleY, 100, 100);

            // Draw the score
            e.Graphics.DrawString($"Score: {score}", new Font("Arial", 16), Brushes.Black, 10, 10);
        }
    }

    public static class Input
    {
        public static bool Left;
        public static bool Right;

        public static void KeyDown(Keys key)
        {
            if (key == Keys.Left)
            {
                Left = true;
            }
            else if (key == Keys.Right)
            {
                Right = true;
            }
        }

        public static void KeyUp(Keys key)
        {
            if (key == Keys.Left)
            {
                Left = false;
            }
            else if (key == Keys.Right)
            {
                Right = false;
            }
        }
    }
}
