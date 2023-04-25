using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Programa_3._5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void btnTime_Click(object sender, EventArgs e)
        {
            DateTime fecha = DateTime.Today;
            string formato = "MMM ddd yy d, hh-> mm";

            lblFecha.Text = fecha.ToString(formato);
        }
    }
}
