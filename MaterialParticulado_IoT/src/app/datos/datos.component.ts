import { Component } from '@angular/core';

@Component({
  selector: 'app-datos',
  templateUrl: './datos.component.html',
  styleUrls: ['./datos.component.scss']
})
export class DatosComponent {
  abrirCSV() {
    const urlCSV = 'https://api.thingspeak.com/channels/2266294/feeds.csv?timezone=America/Lima&results=500';

    // Crear un enlace temporal en memoria
    const link = document.createElement('a');
    link.href = urlCSV;
    link.download = 'archivo.csv'; // Nombre del archivo que se descargará

    // Simular un clic en el enlace para iniciar la descarga
    link.click();
  }
  abrirJSON() {
    const urlJSON = 'https://api.thingspeak.com/channels/2266294/feeds.json?timezone=America/Lima&results=500';
    window.open(urlJSON, '_blank');
  }
  abrirXML() {
    const urlXML = 'https://api.thingspeak.com/channels/2266294/feeds.xml?timezone=America/Lima&results=500';
    window.open(urlXML, '_blank');
  }
}
