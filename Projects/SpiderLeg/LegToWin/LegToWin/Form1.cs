using System;
using System.IO.Ports;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace LegToWin
{
    public partial class Form1 : Form
    {
        SerialPort port = new SerialPort("COM3", 9600);
        public Form1()
        {
            InitializeComponent();
        }

        private void hScrollBar1_Scroll(object sender, ScrollEventArgs e)
        {
            port.Open();
            port.Write("1");
            port.Write(" ");
            if (hScrollBar1.Value <= 99)
            {
                port.Write("0");
            }
            port.Write(hScrollBar1.Value.ToString());
            label4.Text = hScrollBar1.Value.ToString();
            port.Close();
            System.Threading.Thread.Sleep(10);
        }

        private void hScrollBar2_Scroll(object sender, ScrollEventArgs e)
        {
            port.Open();
                port.Write("2");
                port.Write(" ");
                if (hScrollBar2.Value <= 99)
                {
                    port.Write("0");
                }
                port.Write(hScrollBar2.Value.ToString());
                label5.Text = hScrollBar2.Value.ToString();
            port.Close();
            System.Threading.Thread.Sleep(10);
        }

        private void hScrollBar3_Scroll(object sender, ScrollEventArgs e)
        {
            port.Open();
                port.Write("3");
                port.Write(" ");
                if (hScrollBar3.Value <= 99)
                {
                    port.Write("0");
                }
                port.Write(hScrollBar3.Value.ToString());
                label6.Text = hScrollBar3.Value.ToString();
            port.Close();
            System.Threading.Thread.Sleep(10);
        }
    }
}
