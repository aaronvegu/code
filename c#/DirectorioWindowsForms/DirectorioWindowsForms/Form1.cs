using MongoDB.Driver;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using MongoDB.Bson;
using MongoDB.Driver;

namespace DirectorioWindowsForms
{
    public partial class Form1 : Form
    {

        private Persona persona = new Persona();
        private int edit_index = -1;
        private MongoHelper mongo;

        public Form1(MongoHelper mongo)
        {
            this.mongo = mongo;
            InitializeComponent();
            actualizarGrid();
        }

        private async void dgvDatos_DoubleClick(object sender, EventArgs e)
        {
            var filter = Builders<Persona>.Filter.Eq("_id",dgvDatos.SelectedCells[0].Value);
            var result = await mongo.colPersona.Find(filter).ToListAsync();
            edit_index = 1;

            persona = result[0];
            txtNombre.Text = persona.Nombre;
            txtApellido.Text = persona.Apellido;
            txtTelefono.Text = persona.Telefono;
            txtCorreo.Text = persona.Correo;
        }

        private void btnNuevo_Click(object sender, EventArgs e)
        {
            limpiar();
            edit_index = -1;
            actualizarGrid();
        }

        private async void actualizarGrid()
        {
            try
            {
                dgvDatos.DataSource = null;
                dgvDatos.DataSource = await mongo.colPersona.Find(new BsonDocument()).ToListAsync();
                dgvDatos.ClearSelection();
            }
            catch(Exception e)
            {
                MessageBox.Show("Hubo un error", "Revise su conexion a internet, falló al conectar a la base de datos", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
        }

        private void limpiar()
        {
            txtNombre.Text = "";
            txtApellido.Text = "";
            txtTelefono.Text = "";
            txtCorreo.Text = "";
        }

        private async void btnGuardar_Click(object sender, EventArgs e)
        {
            Persona per = new Persona();
            per.Nombre = txtNombre.Text;
            per.Apellido = txtApellido.Text;
            per.Telefono = txtTelefono.Text;
            per.Correo = txtCorreo.Text;

            try
            {
                if(edit_index != -1)
                {
                    per.id = persona.id;
                    var filtro = Builders<Persona>.Filter.Eq("_id", per.id);
                    var update = Builders<Persona>.Update.Set("Nombre", per.Nombre).Set("Apellido", per.Apellido).Set("Telefono", per.Telefono).Set("Correo", per.Correo);
                    mongo.colPersona.UpdateOne(filtro, update);
                    persona = new Persona();    
                    edit_index = -1;
                }
                else
                {
                    await mongo.colPersona.InsertOneAsync(per);
                }

                actualizarGrid();
                limpiar();
            } 
            catch(Exception e)
            {
                MessageBox.Show("Hubo un error", "Revise su conexion a internet, falló al conectar a la base de datos", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
        }

        private void btnEliminar_Click(object sender, EventArgs e)
        {
            try
            {
                if(edit_index != -1)
                {
                    var filtro = Builders<Persona>.Filter.Eq("_id", persona.id);
                    var result = await mongo.colPersona.DeleteOneAsync(filtro);
                    edit_index = -1;
                    limpiar();
                    actualizarGrid();
                }
                else
                {
                    MessageBox.Show("Dar doble click para editar o eliminar");
                }
            } 
            catch(Exception e)
            {
                MessageBox.Show("Hubo un error", "Revise su conexion a internet, falló al conectar a la base de datos", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
        }

        private void Nombre_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }
    }
}
