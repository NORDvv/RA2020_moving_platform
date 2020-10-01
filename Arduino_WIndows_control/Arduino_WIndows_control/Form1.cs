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

namespace Arduino_WIndows_control
{
    public partial class Form1 : Form
    {
        int x_coord = 0;
        int y_coord = 0;
        public SerialPort myport;
        int max_x_rotations = 25;
        int max_y_rotations = 25;
        int counter = 0;
        int step_counter = 1;
        int max_steps = 5;

        public Form1()
        {
            InitializeComponent();
            x_coord = 0; //Forward and bacward movement
            y_coord = 0; //Left and right movement
            Y_coord.Text = step_counter + " rotations/click";
            X_coord.Text = "X: 0" + " out of: " + max_x_rotations;
        }

        private void button4_Click(object sender, EventArgs e) //Left click -> now -1 rotation/click
        {
            if (step_counter > 1) {//y_coord > 0) {
                step_counter -= 1;
                Y_coord.Text = step_counter + " rotations/click";
                //X_coord.Text = "X: " + x_coord + " out of: " + max_x_rotations;


                //Code to send the command to arduino. Credits to: https://www.c-sharpcorner.com/article/controlling-arduino-with-windows-form-application/
                myport = new SerialPort();
                myport.BaudRate = 9600;
                myport.PortName = "COM5";
                myport.Open();
                myport.WriteLine("L");
                myport.Close();
            } else {
                Y_coord.Text = step_counter + " - Min rotations!";
            }
           
        }

        private void Forward_Click(object sender, EventArgs e)//Forward click
        {
            if (x_coord + step_counter <= max_x_rotations)
            {
                x_coord += step_counter;
                //Y_coord.Text = "Y: " + y_coord + " out of: " + max_y_rotations;
                X_coord.Text = "X: " + x_coord + " out of: " + max_x_rotations;


                //Code to send the command to arduino. Credits to: https://www.c-sharpcorner.com/article/controlling-arduino-with-windows-form-application/
                myport = new SerialPort();
                myport.BaudRate = 9600;
                myport.PortName = "COM5";
                myport.Open();
                myport.WriteLine("F");
                myport.Close();
            }
            else
            {
                X_coord.Text = "X: Forward limit!" + " X: " + x_coord;
            }
        }

        private void Right_Click(object sender, EventArgs e)//Right click -> now +1 rotations/click
        {
            if (step_counter < max_steps)
            {
                step_counter += 1;
                Y_coord.Text = step_counter + " rotations/cycle";
                //X_coord.Text = "X: " + x_coord + " out of: " + max_x_rotations;


                //Code to send the command to arduino. Credits to: https://www.c-sharpcorner.com/article/controlling-arduino-with-windows-form-application/
                myport = new SerialPort();
                myport.BaudRate = 9600;
                myport.PortName = "COM5";
                myport.Open();
                myport.WriteLine("R");
                myport.Close();
            }
            else
            {
                Y_coord.Text = step_counter + " - Max rotations/click";
            }
        }

        private void Backward_Click(object sender, EventArgs e)//Backwards click
        {
            if (x_coord - step_counter >= 0)
            {
                x_coord -= step_counter;
                //Y_coord.Text = "Y: " + y_coord + " out of: " + max_y_rotations;
                X_coord.Text = "X: " + x_coord + " out of: " + max_x_rotations;


                //Code to send the command to arduino. Credits to: https://www.c-sharpcorner.com/article/controlling-arduino-with-windows-form-application/
                myport = new SerialPort();
                myport.BaudRate = 9600;
                myport.PortName = "COM5";
                myport.Open();
                myport.WriteLine("B");
                myport.Close();
            }
            else
            {
                X_coord.Text = "X: Back limit!" + " X: " + x_coord;
            }
        }

        private void X_coord_Click(object sender, EventArgs e)
        {
            //do nothing here
        }

        private void Y_coord_Click(object sender, EventArgs e)
        {
            //do nothing here
        }

        private void statusIcon_Click(object sender, EventArgs e)
        {
            statusIcon.BackColor = Color.Red;
            if (x_coord > 0 || y_coord > 0 || step_counter > 1)
            {
                for (; step_counter > 1; step_counter--) //Reseting number of rotations per click
                {
                    //Code to send the command to arduino. Credits to: https://www.c-sharpcorner.com/article/controlling-arduino-with-windows-form-application/
                    myport = new SerialPort();
                    myport.BaudRate = 9600;
                    myport.PortName = "COM5";
                    myport.Open();
                    myport.WriteLine("L");
                    myport.Close();
                }

                for (; x_coord > 0;) //Reseting forward movement
                {
                    if (x_coord > 0)
                    {
                        x_coord -= 1;


                        //Code to send the command to arduino. Credits to: https://www.c-sharpcorner.com/article/controlling-arduino-with-windows-form-application/
                        myport = new SerialPort();
                        myport.BaudRate = 9600;
                        myport.PortName = "COM5";
                        myport.Open();
                        myport.WriteLine("B");
                        myport.Close();
                    }
                    else
                    {
                        X_coord.Text = "X: Back limit!!!";
                    }
                }

                /*for (; y_coord > 0;) // Resetting right movement (towards communism) TODO
                {
                    if (y_coord > 0)
                    {
                        y_coord -= 1;

                        //Code to send the command to arduino. Credits to: https://www.c-sharpcorner.com/article/controlling-arduino-with-windows-form-application/
                        myport = new SerialPort();
                        myport.BaudRate = 9600;
                        myport.PortName = "COM5";
                        myport.Open();
                        myport.WriteLine("L");
                        myport.Close();
                    }
                    else
                    {
                        Y_coord.Text = "Y: Left limit!!!";
                    }
                }*/

            }
            Y_coord.Text = step_counter + " rotations/cycle";
            X_coord.Text = "X: " + x_coord + " out of: " + max_x_rotations;
            statusIcon.BackColor = Color.Blue;
        }

        private void label1_Click(object sender, EventArgs e) //Label descriptor for reset button
        {

        }

    }
}
