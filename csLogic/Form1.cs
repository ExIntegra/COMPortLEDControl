using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;

namespace csLogic
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        SerialPort port;
        private void button1_Click(object sender, EventArgs e)//yellowLED on
        {
            port = new SerialPort("COM256", 9600, Parity.None, 8, StopBits.One);
            port.Open();
            port.Write("YellowON");
            port.Close();
        }

        private void button2_Click(object sender, EventArgs e)//yellowLED off
        {
            port = new SerialPort("COM256", 9600, Parity.None, 8, StopBits.One);
            port.Open();
            port.Write("YellowOFF");
            port.Close();

        }

        private void button3_Click(object sender, EventArgs e)
        {
            port = new SerialPort("COM256", 9600, Parity.None, 8, StopBits.One);
            port.Open();
            port.Write("RedON");
            port.Close();

        }

        private void button4_Click(object sender, EventArgs e)
        {
            port = new SerialPort("COM256", 9600, Parity.None, 8, StopBits.One);
            port.Open();
            port.Write("RedON");
            port.Close();

        }
    }
}
