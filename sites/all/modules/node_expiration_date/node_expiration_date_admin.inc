<?php 
/**
* @file
* Resultado de llamadas a páginas de administración para el módulo
* Node Expiration Date.
*/ 

/**
* Constructor del formulario para configurar el módulo.
*
*/
function node_expiration_date_admin_settings() {
/**
* Con node_type_get_types() se obtiene la información de todos los tipos
* de contenido, cada uno como un objeto, por lo que hay que seleccionar
* sólo los nombres de los tipo de contenido para mostrarlos en las opciones.
*/
$content_types_list = node_type_get_types();
f