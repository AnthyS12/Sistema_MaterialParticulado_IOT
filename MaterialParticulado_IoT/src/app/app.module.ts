import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
import { BrowserAnimationsModule } from '@angular/platform-browser/animations';
import { HttpClientModule } from '@angular/common/http';
import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { BodyComponent } from './body/body.component';
import { SidenavComponent } from './sidenav/sidenav.component';
import { MediaComponent } from './media/media.component';
import { InicioComponent } from './inicio/inicio.component';
import { SensorComponent } from './sensor/sensor.component';
import { MapaComponent } from './mapa/mapa.component';
import { DatosComponent } from './datos/datos.component';
import { GraficaComponent } from './grafica/grafica.component';
import { ContactoComponent } from './contacto/contacto.component';

@NgModule({
  declarations: [
    AppComponent,
    BodyComponent,
    SidenavComponent,
    MediaComponent,
    InicioComponent,
    SensorComponent,
    MapaComponent,
    DatosComponent,
    GraficaComponent,
    ContactoComponent
  ],
  imports: [
    BrowserModule,
    AppRoutingModule,
    HttpClientModule,
    BrowserAnimationsModule
  ],
  providers: [],
  bootstrap: [AppComponent]
})
export class AppModule { }
