namespace DirectorioWindowsForms
{
    partial class Form1
    {
        /// <summary>
        /// Variable del diseñador necesaria.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Limpiar los recursos que se estén usando.
        /// </summary>
        /// <param name="disposing">true si los recursos administrados se deben desechar; false en caso contrario.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Código generado por el Diseñador de Windows Forms

        /// <summary>
        /// Método necesario para admitir el Diseñador. No se puede modificar
        /// el contenido de este método con el editor de código.
        /// </summary>
        private void InitializeComponent()
        {
            this.Nombre = new System.Windows.Forms.Label();
            this.Apellido = new System.Windows.Forms.Label();
            this.Telefono = new System.Windows.Forms.Label();
            this.Correo = new System.Windows.Forms.Label();
            this.txtApellido = new System.Windows.Forms.TextBox();
            this.txtNombre = new System.Windows.Forms.TextBox();
            this.txtTelefono = new System.Windows.Forms.TextBox();
            this.txtCorreo = new System.Windows.Forms.TextBox();
            this.boton_n = new System.Windows.Forms.Button();
            this.boton_g = new System.Windows.Forms.Button();
            this.boton_e = new System.Windows.Forms.Button();
            this.dgvDatos = new System.Windows.Forms.DataGridView();
            ((System.ComponentModel.ISupportInitialize)(this.dgvDatos)).BeginInit();
            this.SuspendLayout();
            // 
            // Nombre
            // 
            this.Nombre.AutoSize = true;
            this.Nombre.Font = new System.Drawing.Font("Arial Narrow", 12F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.Nombre.ForeColor = System.Drawing.SystemColors.ActiveCaptionText;
            this.Nombre.Location = new System.Drawing.Point(53, 39);
            this.Nombre.Name = "Nombre";
            this.Nombre.Size = new System.Drawing.Size(57, 20);
            this.Nombre.TabIndex = 0;
            this.Nombre.Text = "Nombre";
            this.Nombre.Click += new System.EventHandler(this.Nombre_Click);
            // 
            // Apellido
            // 
            this.Apellido.AutoSize = true;
            this.Apellido.Font = new System.Drawing.Font("Arial Narrow", 12F);
            this.Apellido.Location = new System.Drawing.Point(53, 95);
            this.Apellido.Name = "Apellido";
            this.Apellido.Size = new System.Drawing.Size(59, 20);
            this.Apellido.TabIndex = 1;
            this.Apellido.Text = "Apellido";
            // 
            // Telefono
            // 
            this.Telefono.AutoSize = true;
            this.Telefono.Font = new System.Drawing.Font("Arial Narrow", 12F);
            this.Telefono.Location = new System.Drawing.Point(53, 155);
            this.Telefono.Name = "Telefono";
            this.Telefono.Size = new System.Drawing.Size(61, 20);
            this.Telefono.TabIndex = 2;
            this.Telefono.Text = "Teléfono";
            // 
            // Correo
            // 
            this.Correo.AutoSize = true;
            this.Correo.Font = new System.Drawing.Font("Arial Narrow", 12F);
            this.Correo.Location = new System.Drawing.Point(53, 213);
            this.Correo.Name = "Correo";
            this.Correo.Size = new System.Drawing.Size(42, 20);
            this.Correo.TabIndex = 3;
            this.Correo.Text = "Email";
            // 
            // txtApellido
            // 
            this.txtApellido.Location = new System.Drawing.Point(149, 95);
            this.txtApellido.Name = "txtApellido";
            this.txtApellido.Size = new System.Drawing.Size(422, 20);
            this.txtApellido.TabIndex = 5;
            // 
            // txtNombre
            // 
            this.txtNombre.Location = new System.Drawing.Point(149, 39);
            this.txtNombre.Name = "txtNombre";
            this.txtNombre.Size = new System.Drawing.Size(422, 20);
            this.txtNombre.TabIndex = 6;
            // 
            // txtTelefono
            // 
            this.txtTelefono.Location = new System.Drawing.Point(149, 155);
            this.txtTelefono.Name = "txtTelefono";
            this.txtTelefono.Size = new System.Drawing.Size(422, 20);
            this.txtTelefono.TabIndex = 7;
            // 
            // txtCorreo
            // 
            this.txtCorreo.Location = new System.Drawing.Point(149, 213);
            this.txtCorreo.Name = "txtCorreo";
            this.txtCorreo.Size = new System.Drawing.Size(422, 20);
            this.txtCorreo.TabIndex = 8;
            // 
            // boton_n
            // 
            this.boton_n.Font = new System.Drawing.Font("Arial Narrow", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.boton_n.Location = new System.Drawing.Point(589, 161);
            this.boton_n.Name = "boton_n";
            this.boton_n.Size = new System.Drawing.Size(88, 30);
            this.boton_n.TabIndex = 9;
            this.boton_n.Text = "Nuevo";
            this.boton_n.UseVisualStyleBackColor = true;
            this.boton_n.Click += new System.EventHandler(this.btnNuevo_Click);
            // 
            // boton_g
            // 
            this.boton_g.Location = new System.Drawing.Point(683, 161);
            this.boton_g.Name = "boton_g";
            this.boton_g.Size = new System.Drawing.Size(84, 30);
            this.boton_g.TabIndex = 10;
            this.boton_g.Text = "Guardar";
            this.boton_g.UseVisualStyleBackColor = true;
            this.boton_g.Click += new System.EventHandler(this.btnGuardar_Click);
            // 
            // boton_e
            // 
            this.boton_e.Location = new System.Drawing.Point(601, 197);
            this.boton_e.Name = "boton_e";
            this.boton_e.Size = new System.Drawing.Size(144, 36);
            this.boton_e.TabIndex = 11;
            this.boton_e.Text = "Eliminar";
            this.boton_e.UseVisualStyleBackColor = true;
            this.boton_e.Click += new System.EventHandler(this.btnEliminar_Click);
            // 
            // dgvDatos
            // 
            this.dgvDatos.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
            this.dgvDatos.EditMode = System.Windows.Forms.DataGridViewEditMode.EditProgrammatically;
            this.dgvDatos.Location = new System.Drawing.Point(101, 262);
            this.dgvDatos.Name = "dgvDatos";
            this.dgvDatos.SelectionMode = System.Windows.Forms.DataGridViewSelectionMode.FullRowSelect;
            this.dgvDatos.Size = new System.Drawing.Size(576, 150);
            this.dgvDatos.TabIndex = 12;
            this.dgvDatos.DoubleClick += new System.EventHandler(this.dgvDatos_DoubleClick);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(770, 450);
            this.Controls.Add(this.dgvDatos);
            this.Controls.Add(this.boton_e);
            this.Controls.Add(this.boton_g);
            this.Controls.Add(this.boton_n);
            this.Controls.Add(this.txtCorreo);
            this.Controls.Add(this.txtTelefono);
            this.Controls.Add(this.txtNombre);
            this.Controls.Add(this.txtApellido);
            this.Controls.Add(this.Correo);
            this.Controls.Add(this.Telefono);
            this.Controls.Add(this.Apellido);
            this.Controls.Add(this.Nombre);
            this.Name = "Form1";
            this.Text = "Form1";
            ((System.ComponentModel.ISupportInitialize)(this.dgvDatos)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label Nombre;
        private System.Windows.Forms.Label Apellido;
        private System.Windows.Forms.Label Telefono;
        private System.Windows.Forms.Label Correo;
        private System.Windows.Forms.TextBox txtApellido;
        private System.Windows.Forms.TextBox txtNombre;
        private System.Windows.Forms.TextBox txtTelefono;
        private System.Windows.Forms.TextBox txtCorreo;
        private System.Windows.Forms.Button boton_n;
        private System.Windows.Forms.Button boton_g;
        private System.Windows.Forms.Button boton_e;
        private System.Windows.Forms.DataGridView dgvDatos;
    }
}

