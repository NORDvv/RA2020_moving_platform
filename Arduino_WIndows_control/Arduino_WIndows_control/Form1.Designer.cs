namespace Arduino_WIndows_control
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.Forward = new System.Windows.Forms.Button();
            this.Right = new System.Windows.Forms.Button();
            this.Backward = new System.Windows.Forms.Button();
            this.Left = new System.Windows.Forms.Button();
            this.X_coord = new System.Windows.Forms.Label();
            this.Y_coord = new System.Windows.Forms.Label();
            this.statusIcon = new System.Windows.Forms.PictureBox();
            this.label1 = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.statusIcon)).BeginInit();
            this.SuspendLayout();
            // 
            // Forward
            // 
            this.Forward.Location = new System.Drawing.Point(357, 39);
            this.Forward.Name = "Forward";
            this.Forward.Size = new System.Drawing.Size(75, 50);
            this.Forward.TabIndex = 0;
            this.Forward.Text = "Forward";
            this.Forward.UseVisualStyleBackColor = true;
            this.Forward.Click += new System.EventHandler(this.Forward_Click);
            // 
            // Right
            // 
            this.Right.Location = new System.Drawing.Point(460, 109);
            this.Right.Name = "Right";
            this.Right.Size = new System.Drawing.Size(75, 48);
            this.Right.TabIndex = 1;
            this.Right.Text = "+1 rotation";
            this.Right.UseVisualStyleBackColor = true;
            this.Right.Click += new System.EventHandler(this.Right_Click);
            // 
            // Backward
            // 
            this.Backward.Location = new System.Drawing.Point(357, 178);
            this.Backward.Name = "Backward";
            this.Backward.Size = new System.Drawing.Size(75, 51);
            this.Backward.TabIndex = 2;
            this.Backward.Text = "Backward";
            this.Backward.UseVisualStyleBackColor = true;
            this.Backward.Click += new System.EventHandler(this.Backward_Click);
            // 
            // Left
            // 
            this.Left.Location = new System.Drawing.Point(229, 109);
            this.Left.Name = "Left";
            this.Left.Size = new System.Drawing.Size(75, 48);
            this.Left.TabIndex = 3;
            this.Left.Text = "-1 rotation";
            this.Left.UseVisualStyleBackColor = true;
            this.Left.Click += new System.EventHandler(this.button4_Click);
            // 
            // X_coord
            // 
            this.X_coord.AutoSize = true;
            this.X_coord.Location = new System.Drawing.Point(335, 109);
            this.X_coord.Name = "X_coord";
            this.X_coord.Size = new System.Drawing.Size(46, 13);
            this.X_coord.TabIndex = 4;
            this.X_coord.Text = "X: None";
            this.X_coord.Click += new System.EventHandler(this.X_coord_Click);
            // 
            // Y_coord
            // 
            this.Y_coord.AutoSize = true;
            this.Y_coord.Location = new System.Drawing.Point(335, 144);
            this.Y_coord.Name = "Y_coord";
            this.Y_coord.Size = new System.Drawing.Size(78, 13);
            this.Y_coord.TabIndex = 5;
            this.Y_coord.Text = "1 rotation/click";
            this.Y_coord.Click += new System.EventHandler(this.Y_coord_Click);
            // 
            // statusIcon
            // 
            this.statusIcon.BackColor = System.Drawing.SystemColors.HotTrack;
            this.statusIcon.Location = new System.Drawing.Point(627, 109);
            this.statusIcon.Name = "statusIcon";
            this.statusIcon.Size = new System.Drawing.Size(100, 50);
            this.statusIcon.TabIndex = 6;
            this.statusIcon.TabStop = false;
            this.statusIcon.Click += new System.EventHandler(this.statusIcon_Click);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(583, 89);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(173, 13);
            this.label1.TabIndex = 7;
            this.label1.Text = "Click to reset. Wait, until blue again";
            this.label1.Click += new System.EventHandler(this.label1_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.statusIcon);
            this.Controls.Add(this.Y_coord);
            this.Controls.Add(this.X_coord);
            this.Controls.Add(this.Left);
            this.Controls.Add(this.Backward);
            this.Controls.Add(this.Right);
            this.Controls.Add(this.Forward);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.statusIcon)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button Forward;
        private System.Windows.Forms.Button Right;
        private System.Windows.Forms.Button Backward;
        private System.Windows.Forms.Button Left;
        private System.Windows.Forms.Label X_coord;
        private System.Windows.Forms.Label Y_coord;
        private System.Windows.Forms.PictureBox statusIcon;
        private System.Windows.Forms.Label label1;
    }
}

