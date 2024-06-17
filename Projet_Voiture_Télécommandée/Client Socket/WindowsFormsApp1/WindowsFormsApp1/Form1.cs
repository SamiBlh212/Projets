using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using SharpDX.XInput;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {

        Socket s = new Socket(AddressFamily.InterNetwork, SocketType.Stream, ProtocolType.Tcp);
        private static Controller controller;
        private State State;

        public Form1()
        {
            InitializeComponent();
            controller = new Controller(UserIndex.One);
        }

        private void button1_Click(object sender, EventArgs e)
        {
            IPAddress ipAddress = IPAddress.Parse(txtHost.Text);
            int Port = int.Parse(txtPort.Text);
            Connect1(Port, ipAddress, s);
        }

        private static void Connect1(int port, IPAddress ip, Socket sock)
        {
            
            Console.WriteLine("Establishing Connection to {0}", ip);
            sock.Connect(ip, port);
            Console.WriteLine("Connection established");
        }

        private void btnDisconnect_Click(object sender, EventArgs e)
        {
            
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
                label4.Text = State.Gamepad.ToString() + "\n";
                label4.Text += "Btn : " + Btn + "\n";
                LeftTrigger = State.Gamepad.LeftTrigger;
                RightTrigger = State.Gamepad.RightTrigger;
                label4.Text += " " + LeftTrigger + " " + RightTrigger + "\n";
            }
        }

        private void btnSend_Click(object sender, EventArgs e)
        {
            string msg = txtData.Text ;
            byte[] bytemsg = Encoding.ASCII.GetBytes(msg);
            s.Send(bytemsg);
            
        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            LoadController();
            int x, y;
            int LeftTrigger, RightTrigger;
            int LeftThumbX, RightThumbX;
            int LeftThumbY, RightThumbY;
            String Btn, Pad;

            LeftTrigger = State.Gamepad.LeftTrigger;
            RightTrigger = State.Gamepad.RightTrigger;
            Btn = State.Gamepad.Buttons.ToString();

            if (RightTrigger > 0)
            {
                string msg = txtData.Text;
                byte[] bytemsg = Encoding.ASCII.GetBytes("a");
                s.Send(bytemsg);
            }

            if (LeftTrigger > 0)
            {
                string msg = txtData.Text;
                byte[] bytemsg = Encoding.ASCII.GetBytes("b");
                s.Send(bytemsg);
            }

            if (Btn == "DPadLeft")
            {
                string msg = txtData.Text;
                byte[] bytemsg = Encoding.ASCII.GetBytes("c");
                s.Send(bytemsg);
            }

            if (Btn == "DPadRight")
            {
                string msg = txtData.Text;
                byte[] bytemsg = Encoding.ASCII.GetBytes("d");
                s.Send(bytemsg);
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            Application.Exit();
        }
    }
}
