using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Programa_3._4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnColor_Click(object sender, EventArgs e)
        {
            if(colorDialog1.ShowDialog() == DialogResult.OK)
            {
                lblMensaje.ForeColor = colorDialog1.Color;
            }
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            colorDialog1.Color = Color.FromArgb(120, 54, 67);
        }
    }
}
