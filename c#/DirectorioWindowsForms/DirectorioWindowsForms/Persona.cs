using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using MongoDB;
using MongoDB.Bson.Serialization.Attributes;
using MongoDB.Bson.Serialization.IdGenerator;
using MongoDB.Bson;

namespace DirectorioWindowsForms
{
    public class Persona
    {
        [BsonId]
        public ObjectId id { get; set; }
        [BsonElement("Nombre")]
        public string Nombre { get; set; }
        [BsonElement("Apellido")]
        public string Apellido { get; set; }
        [BsonElement("Telefono")]
        public string Telefono { get; set; }
        [BsonElement("Correo")]
        public string Correo { get; set; }
    }
}
