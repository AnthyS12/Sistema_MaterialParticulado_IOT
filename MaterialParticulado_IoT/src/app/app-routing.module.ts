import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
import { MediaComponent } from './media/media.component';
import { ContactoComponent } from './contacto/contacto.component';
import { GraficaComponent } from './grafica/grafica.component';
import { DatosComponent } from './datos/datos.component';
import { MapaComponent } from './mapa/mapa.component';
import { SensorComponent } from './sensor/sensor.component';
import { InicioComponent } from './inicio/inicio.component';

const routes: Routes = [
  { path: '', redirectTo: 'inicio', pathMatch: 'full'},
  { path: 'inicio', component: InicioComponent},
  { path: 'sensor', component: SensorComponent},
  { path: 'grafica', component: GraficaComponent},
  { path: 'media', component: MediaComponent},
  { path: 'contacto', component: ContactoComponent},
  { path: 'mapa', component: MapaComponent},
  { path: 'datos', component: DatosComponent},
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule { }
