using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using SharpDX.XInput;

namespace Gamos
{
    public partial class Form1 : Form
    {
        private static Controller controller;
        private State State;
        public Form1()
        {
            InitializeComponent();
            controller = new Controller(UserIndex.One);
        }

        private void LoadController()
        {
            int x, y;
            int LeftTrigger, RightTrigger;
            int LeftThumbX, RightThumbX;
            int LeftThumbY, RightThumbY;
            String Btn, Pad;

            if (!controller.IsConnected)
            {
                textBox1.BackColor = Color.Red;
            }
            else
            {
                textBox1.BackColor = Color.Green;
                State = controller.GetState();
                Btn = State.Gamepad.Buttons.ToString();
                label1.Text = State.Gamepad.ToString() + "\n";
                label1.Text += "Btn : " + Btn + "\n";
                LeftTrigger = State.Gamepad.LeftTrigger;
                RightTrigger = State.Gamepad.RightTrigger;
                label1.Text += " " + LeftTrigger + " " + RightTrigger + "\n";
            }
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            LoadController();
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
