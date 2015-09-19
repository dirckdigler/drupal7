<?php
/**
* @file
* Resultado de llamadas a páginas de administración para el módulo
* Enroll college courses module.
*/ 

/**
* Constructor del formulario para configurar el módulo.
*
*/
function enroll_courses_teacher_settings($form, &$form_state){

  return $form;
}
/**
* Implements the webform ....................
*/
function enroll_courses_student_settings($form, &$form_state){

  $form['tabs'] = array (
    '#type' => 'vertical_tabs',
  );
  $form['tabs']['account_info'] = array(
    '#type' => 'fieldset',
    '#title' => t('Courses'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['tabs']['account_info']['email'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail'),
    '#default_value' => 'E-mail de usuario',
    '#size' => 30,
    '#maxlength' => 30,
    '#required' => TRUE,
  );
  return $form;
}
/**
* Implements the webform to add courses
*/
function enroll_courses_add($form, &$form_state){
  
  global $user;
  
  $form['name_course'] = array(
    '#type' => 'textfield',
    '#title' => t('Name course'),
    '#size' => 30,
    '#maxlength' => 30,
    '#required' => TRUE,
    '#description' => 'Blank spaces are allowed. No punctuation except for periods, hyphens, single quotes (apostrophes) and underscores are allowed',
  );
   $form['name_career'] = array(
    '#type' => 'select',
    '#title' => t('Name career'),
    '#default_value' => 'engineering_systems',
    '#options' => array(
      'engineering_systems' => t('Engineering Systems'),
      'social_work' => t('Social work'),
      'social_comunication' => t('Social comunication'),
      'geology' => t('Geology'),
      'psicology' => t('Psicology'),
    ),
    '#description' => t('Select a name career'),
);
   $form['submit'] = array(
    '#type' => 'submit', 
    '#value' => 'Submit',
  );
  return $form;
}

$form['tabs']['personal_info']['months'] = array(
'#type' => 'select',
'#title' => t('Month'),
'#default_value' => 'january',
'#options' => array(
'january' => t('January'),
'february' => t('February'),
'march' => t('March'),
'april' => t('April'),
'may' => t('May'),
'june' => t('June'),
'july' => t('July'),
'august' => t('August'),
'september' => t('September'),
'october' => t('October'),
'november' => t('November'),
'december' => t('December'),
),
'#description' => t('Selecciona mes de nacimiento'),
);
function enroll_courses_add_submit($form, &$form_state) {
 
  $result = db_insert('enroll_courses_add')
           ->fields(array(
             'name_course' => $form_state['values']['name_course'],
             'name_career' => $form_state['values']['name_career'],
           ))
           ->execute()    ;
  drupal_set_message ("<strong>Su cuenta de usuario ha sido creada correctamente.</strong>");
  drupal_goto("");
}


/*case 'user_profile_form': //formulario de edición de usuario para los  que ya estan registrados
      $uid = (int)$form['#user']->uid;
      $account = user_load($uid);
      //$var_temporal = user_load($form['#user']->uid);  //se recomienda utilizar como variable local $account en lugar de $var_temporal
      $form['firstname'] = array(
       '#type' => 'textfield',
       '#title' => t('First name'),
       '#description' => t('First name'),
       '#required' => 1,
       '#lenght' => 255,
       '#default_value' => (($account->data['firstname']) ? $account->data['firstname'] : ''),
      );
      $form['lastname'] = array(
       '#type' => 'textfield',
       '#title' => t('Last name'),
       '#description' => t('Last name'),
       '#required' => 1,
       '#lenght' => 255,
       '#default_value' => (($account->data['lastname']) ? $account->data['lastname'] : ''),
      );  
      $form['identification'] = array(
        '#type' => 'textfield',
        '#title' => 'Identification',
        '#description' => t('Identification'),
        '#required' => 1,
        '#lenght' => 255,
        '#default_value' => (($account->data['identification']) ? $account->data['identification'] : ''),
      );  
      $form['college_program'] = array(
        '#type' => 'select',
        '#title' => t('College program'),
        '#default_value' => 'Engineering systems',
        '#options' => array(
          'engineering_systems' => t('Engineering systems'),
          'social_work' => t('Social work'),
        ),
        '#description' => t('Select your college program'),
        '#default_value' => (($account->data['college_program']) ? $account->data['college_program'] : ''),
      );
      break;*/