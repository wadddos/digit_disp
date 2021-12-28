#include "button.h"
//------------------------------------------------------------------------------
// Функция опроса кнопок. Код кнопки должен занимать до 6 младших бит.
// IDDLE - 8 битный код если ничего не нажато.
// Вызов функции в прерывании или по флагу от таймера. По умолчанию все посчитано для периода опроса 10 мс.
// Долгое нажатие - 1с (параметр L_TIME), более долгое нажатие - 2с (параметр XL_TIME).
// Дребезг фильтруется и при нажатии, и при отпускании.
// При отсутствии нажатия функция возвращает 0. 
// После нажатия возвращаемое значение станет равно 0 только после отпускания кнопки
// с учетом дребезга. Можно использовать для реакции обработчика на событие отпускания.  

unsigned char buttons_polling(unsigned char button_code)
{
    unsigned char static on_count = 1;      // счетчик периодов опроса для фильтрации дребезга нажатия
	unsigned char static off_count = 0;     // счетчик периодов опроса для фильтрации дребезга отпускания
	unsigned char static press = 0;         // переменная для записи типа нажатия (короткое, долгое, очень долгое)
	unsigned char static button_save = 0;   // здесь запоминается код кнопки для сравнения с текущим значением и формируется возвращаемое значение
	
	
	if(!button_save) button_save = button_code;
	
	if((button_code == button_save)&&(button_code!=IDDLE))
    {
	    on_count++;
        off_count = 0;
		if((on_count > S_TIME)&&!press)  {press = S_PRESS;}
		if(on_count > L_TIME)            {press = L_PRESS;}
		if(on_count > XL_TIME)           {press = XL_PRESS; on_count = XL_TIME;}		
	}
    else
	{
		on_count = 0;
        button_save = 0;
        if(press) off_count++;
		if(off_count > S_TIME) {off_count = S_TIME; press = 0;}		
    }
	
	button_save = (button_save << 2) | press;
	return button_save;
} 

    // Формат возвращаемого значения:
    //      0bXXXXXXXX;
	//        ||||||||
    // 		  |||||||+--++ тип нажатия
    //		  ||||||+---+ 
    //		  |||||+----++++++++ код кнопки
    //		  ||||+-----+++++++
    //		  |||+------++++++ 
    //		  ||+-------++++
    //		  |+--------++
    //		  +---------+