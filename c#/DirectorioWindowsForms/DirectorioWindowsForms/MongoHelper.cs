using System;
using System.Collections.Generic;
using System.Text;
using System.Windows.Forms;
using MongoDB.Driver;

namespace DirectorioWindowsForms
{
    public class MongoHelper
    {
        public IMongoClient client { get; set; }
        public IMongoDatabase database { get; set; }

        public IMongoCollection<Persona> colPersona;
        public string MongoConnection = "mongodb+srv://admin:123@directoriowf-rhpfi.mongodb.net/test?retryWrites=true&w=majority";
        public string MongoDatabase = "DirectorioPOE";

        public void connectToDatabase()
        {
            try
            {
                client = new MongoClient(MongoConnection);
                database = client.GetDatabase(MongoDatabase);
                colPersona = database.GetCollection<Persona>("Directorio");
            }
            catch(Exception e)
            {
                MessageBox.Show("Hubo un error", "Revise su conexion a internet, falló al conectar a la base de datos", MessageBoxButtons.OK, MessageBoxIcon.Exclamation);
            }
        }
    }
}
