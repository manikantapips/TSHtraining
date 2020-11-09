command to run playback turoial-1
	gcc playback-tutorial-1.c -o playback-tutorial-1 `pkg-config --cflags --libs gstreamer-1.0`
     
     
Command to Run playback tutorial-2
	gcc playback-tutorial-2.c -o playback-tutorial-2 `pkg-config --cflags --libs gstreamer-1.0`
	
	
Command to Run playback tutorial-3
	gcc playback-tutorial-3.c -o playback-tutorial-3 `pkg-config --cflags --libs gstreamer-1.0 gstreamer-audio-1.0`	
	
	
Command to Run playback tutorial-4	
	gcc playback-tutorial-4.c -o playback-tutorial-4 `pkg-config --cflags --libs gstreamer-1.0`
	
	
	
	
	
	
About gstreamer:

GStreamer is an extremely powerful and versatile framework for creating streaming media applications.
GStreamer is a framework for constructing graphs of various filters (termed elements here) that will handle streaming media

GStreamer is built on top of the GObject (for object orientation) and GLib (for common algorithms) libraries, which means that every now and then you will have to call functions of these libraries. 

the GStreamer framework uses GObject

You can always tell which library you are calling because all GStreamer functions, structures and types have the gst_ prefix, whereas GLib and GObject use g_.


-------------------------------------------------------------------------------------------------------------------------------------------


GstElement:

GstElement is the abstract base class needed to construct an element that can be used in a GStreamer pipeline.

inorder to create object for abstract class it must be inherited from another class 
in order to call methods

GObject
    ╰──GInitiallyUnowned
        ╰──GstObject
            ╰──GstElement
                ╰──GstBin
                    ╰──GstPipeline

--------------------------------------------------------------------------------------------------------------------------------------------


The GStreamer library(Gst library)should be initialized with gst_init before it can be used.

 // initialize the GStreamer library
   gst_init (int* argc,char*** argv)
It's allowed to pass two NULL pointers to gst_init in case you don't want to pass the command line args to GStreamer.

Initializes the GStreamer library, setting up internal path lists, registering built-in elements, and loading standard plugins.

--------------------------------------------------------------------------------------------------
GstElementFactory is used to create instances of elements. A GstElementFactory can be added to a GstPlugin as it is also a GstPluginFeature.

Use the gst_element_factory_find and gst_element_factory_create functions to create element instances or use gst_element_factory_make as a convenient shortcut

GstElement * gst_element_factory_make(GstElementFactory *factory, GstElement * element)

Parameters:	

    factoryname (str) – a named factory to instantiate
    name (str or None) – name of new element, or None to automatically create a unique name

Returns:	
	new Gst.Element or None if unable to create element
Return type:	
	Gst.Element or None

-----------------------------------------------------------------------------------------------------------------

GstBus *gst_element_get_bus(GstElement * element)

Returns the bus of the element. Note that only a GstPipeline will provide a bus for the application.

Parameters:
element –
	a GstElement to get the bus of.
Returns ( [transfer: full] [nullable] )–the element's GstBus. unref after usage.

------------------------------------------------------------------------------------------------------------------
g_object_set ()

void g_object_set(gpointer object,const gchar *first_property_name, ...);

Sets properties on an object.
object:	a GObject
first_property_name:	name of the first property to set
...:	value for the first property, followed optionally by more name/value pairs, followed by NULL




g_object_get ()

void g_object_get(gpointer object,const gchar *first_property_name, ...);

Gets properties of an object.

In general, a copy is made of the property contents and the caller is responsible for freeing the memory in the appropriate manner for the type, for instance by calling g_free() or g_object_unref(). 

------------------------------------------------------------------------------------------------------------

GstStateChangeReturn   gst_element_set_state (GstElement *element, GstState state);

Parameters:
element
	a GstElement to change state of.

state
	the element's new GstState.


-----------------------------------------------------------------------------------------------------

GMainLoop *g_main_loop_new (GMainContext *context,gboolean is_running);

Creates a new GMainLoop structure.

Parameters:

context
	a GMainContext (if NULL, the default context will be used).
	[nullable]

is_running
	set to TRUE to indicate that the loop is running. This is not very important since calling g_main_loop_run() will set this to TRUE 		anyway.

---------------------------------------------------------------------

void g_main_loop_unref (GMainLoop *loop);

Decreases the reference count on a GMainLoop object by one. If the result is zero, free the loop and free all associated memory.

Parameters:
loop
	a GMainLoop


--------------------------------------------------------------------------------------------------


GIOStatus g_io_channel_read_line (GIOChannel *channel,gchar **str_return,gsize *length,gsize *terminator_pos,GError **error);

Reads a line, including the terminating character(s), from a GIOChannel into a newly-allocated string. str_return will contain allocated memory if the return is G_IO_STATUS_NORMAL.
Parameters:
channel
	a GIOChannel
	 
str_return
	The line read from the GIOChannel, including the line terminator. This data should be freed with g_free() when no longer needed. This 		is a nul-terminated string. If a length of zero is returned, this will be NULL instead.
	[out]

length
	location to store length of the read data, or NULL.
	[out][optional]

terminator_pos
	location to store position of line terminator, or NULL.
	[out][optional]

error
	A location to return an error of type GConvertError or GIOChannelError
	 
Returns
	the status of the operation.

----------------------------------------------------------------------------------------------------------------------

guint64  g_ascii_strtoull (const gchar *nptr,gchar **endptr,guint base);

Converts a string to a guint64 value. This function behaves like the standard strtoull() function does in the C locale. It does this without actually changing the current locale, since that would not be thread-safe.
his function is typically used when reading configuration files or other non-user input that should be locale independent. To handle input from the user you should normally use the locale-sensitive system strtoull() function.

If the correct value would cause overflow, G_MAXUINT64 is returned, and ERANGE is stored in errno. If the base is outside the valid range, zero is returned, and EINVAL is stored in errno. If the string conversion fails, zero is returned, and endptr returns nptr (if endptr is non-NULL).

Parameters:
nptr
	the string to convert to a numeric value.
	 
endptr
	if non-NULL, it returns the character after the last character used in the conversion.
	[out][transfer none][optional]

base
	to be used for the conversion, 2..36 or 0
	 
Returns
	the guint64 value or zero on error.

--------------------------------------------------------------------------------------------------------------------

void g_signal_emit_by_name (gpointer instance,const gchar *detailed_signal, ...);


Emits a signal.

Note that g_signal_emit_by_name() resets the return value to the default if no handlers are connected, in contrast to g_signal_emitv().

Parameters:

instance
	the instance the signal is being emitted on.
	[type GObject.Object]

detailed_signal
	a string of the form "signal-name::detail".
	 

...
	parameters to be passed to the signal, followed by a location for the return value. If the return type of the signal is G_TYPE_NONE, 		the return value location can be omitted.

-------------------------------------------------------------------------------------------------------------------------

gboolean   gst_tag_list_get_string (const GstTagList *list,const gchar *tag,gchar **value);



Copies the contents for the given tag into the value, possibly merging multiple values into one if multiple values are associated with the tag.

Use gst_tag_list_get_string_index (list, tag, 0, value) if you want to retrieve the first string associated with this tag unmodified.

The resulting string in value will be in UTF-8 encoding and should be freed by the caller using g_free when no longer needed. The returned string is also guaranteed to be non-NULL and non-empty.

Free-function: g_free

Parameters:
list
	a GstTagList to get the tag from
	 
tag
	tag to read out
	 
value
	location for the result.
	[out callee-allocates][transfer full]
Returns

	TRUE, if a value was copied, FALSE if the tag didn't exist in the given list.

----------------------------------------------------------------------------------------------------------------------------

This passing of control is done using the idea of "signals". (Note that these signals are not the same as the Unix system signals, and are not implemented using them, although the terminology is almost identical.) When an event occurs, such as the press of a mouse button, the appropriate signal will be "emitted" by the widget that was pressed. This is how GTK does most of its useful work. There are signals that all widgets inherit, such as "destroy", and there are signals that are widget specific, such as "toggled" on a toggle button.

To make a button perform an action, we set up a signal handler to catch these signals and call the appropriate function. This is done by using a function such as:

gulong g_signal_connect( gpointer      *object,
                         const gchar   *name,
                         GCallback     func,
                         gpointer      func_data );

where the first argument is the widget which will be emitting the signal, and the second the name of the signal you wish to catch. The third is the function you wish to be called when it is caught, and the fourth, the data you wish to have passed to this function.

The function specified in the third argument is called a "callback function", and should generally be of the form


__________________________________________________________________________________________________________________________________
gst_bus_add_signal_watch ()

void
gst_bus_add_signal_watch (GstBus *bus);

Adds a bus signal watch to the default main context with the default priority (G_PRIORITY_DEFAULT). It is also possible to use a non-default main context set up using g_main_context_push_thread_default() (before one had to create a bus watch source and attach it to the desired main context 'manually').

After calling this statement, the bus will emit the "message" signal for each message posted on the bus.

This function may be called multiple times. To clean up, the caller is responsible for calling gst_bus_remove_signal_watch() as many times as this function is called.

MT safe.
Parameters

bus
	

a GstBus on which you want to receive the "message" signal

--------------------------------------------------------------------------------------------------------------
gst_element_set_state ()

GstStateChangeReturn
gst_element_set_state (GstElement *element,
                       GstState state);

Sets the state of the element. This function will try to set the requested state by going through all the intermediary states and calling the class's state change function for each.

This function can return GST_STATE_CHANGE_ASYNC, in which case the element will perform the remainder of the state change asynchronously in another thread. An application can use gst_element_get_state() to wait for the completion of the state change or it can wait for a GST_MESSAGE_ASYNC_DONE or GST_MESSAGE_STATE_CHANGED on the bus.

State changes to GST_STATE_READY or GST_STATE_NULL never return GST_STATE_CHANGE_ASYNC.
Parameters

element
	

a GstElement to change state of.
	 

state
	

the element's new GstState.
	 
Returns

Result of the state change using GstStateChangeReturn.

-------------------------------------------------------------------------------------------------------------------



void gst_audio_info_set_format (GstAudioInfo *info,GstAudioFormat format,gint rate,gint channels,const GstAudioChannelPosition *position);

Set the default info for the audio info of format and rate and channels .

Note: This initializes info first, no values are preserved.

Parameters:
info
	a GstAudioInfo
	 
format
	the format
	 
rate
	the samplerate
	 
channels
	the number of channels
	 
position
	the channel positions

The first property that needs to be set on the appsrc is caps. It specifies the kind of data that the element is going to produce, so GStreamer can check if linking with downstream elements is possible (this is, if the downstream elements will understand this kind of data). This property must be a GstCaps object, which is easily built from a string with gst_caps_from_string().
------------------------------------------------------------------------------------------------------------------------------------------


GstCaps *   gst_audio_info_to_caps(GstAudioInfo *info);

Convert the values of info into a GstCaps.

info :
	a GstAudioInfo

Returns :
	the new GstCaps containing the info of info. [transfer full]

-----------------------------------------------------------------------------------------------------------------------------------------

This function is called when the internal queue of appsrc is about to starve (run out of data). The only thing we do here is register a GLib idle function with g_idle_add() that feeds data to appsrc until it is full again. 


guint g_idle_add (GSourceFunc function,gpointer data);

Adds a function to be called whenever there are no higher priority events pending to the default main loop. The function is given the default idle priority, G_PRIORITY_DEFAULT_IDLE. If the function returns FALSE it is automatically removed from the list of event sources and will not be called again.

Parameters:
function
	function to call
	 
data
	data to pass to function .
	 
Returns
	the ID (greater than 0) of the event source.

--------------------------------------------------------------------------------------------------------------------------------------

This function is called when the internal queue of appsrc is full enough so we stop pushing data. Here we simply remove the idle function by using g_source_remove() (The idle function is implemented as a GSource).


gboolean g_source_remove (guint tag);

Removes the source with the given ID from the default main context. You must use g_source_destroy() for sources added to a non-default main context.

parameters:
tag
	the ID of the source to remove.
	 
Returns
	For historical reasons, this function always returns TRUE

--------------------------------------------------------------------------------------------------------------------------------------


GstBuffer *  gst_buffer_new_and_alloc(guint size);

Creates a newly allocated buffer with data of the given size. The buffer memory is not cleared. If the requested amount of memory can't be allocated, the program will abort. Use gst_buffer_try_new_and_alloc() if you want to handle this case gracefully or have gotten the size to allocate from an untrusted source such as a media stream.

Note that when size == 0, the buffer data pointer will be NULL.

parameter:
size :
	the size in bytes of the new buffer's data.

Returns :
	the new GstBuffer. [transfer full]

---------------------------------------------------------------------------------------------------------------------------------------


guint64 gst_util_uint64_scale (guint64 val,guint64 num,guint64 denom);


Scale val by the rational number num / denom , avoiding overflows and underflows and without loss of precision.
This function can potentially be very slow if val and num are both greater than G_MAXUINT32.

Parameters:
val
	the number to scale
	 
num
	the numerator of the scale ratio
	 
denom
	the denominator of the scale ratio
	 
Returns
	val * num / denom . In the case of an overflow, this function returns G_MAXUINT64. If the result is not exactly representable as an 		integer it is truncated. 

---------------------------------------------------------------------------------------------------------------------------------------

GstBus

The GstBus is an object responsible for delivering GstMessage packets in a first-in first-out way from the streaming threads (see GstTask) to the application.

Since the application typically only wants to deal with delivery of these messages from one thread, the GstBus will marshall the messages between different threads. This is important since the actual streaming of media is done in another thread than the application.

The GstBus provides support for GSource based notifications. This makes it possible to handle the delivery in the glib mainloop.

The GSource callback function gst_bus_async_signal_func can be used to convert all bus messages into signal emissions.
-----------------------------------------------------------------------------------------------------------------------------------


GstQuery * gst_query_new_buffering (GstFormat format);


Constructs a new query object for querying the buffering status of a stream.
Free-function: gst_query_unref

Parameters:
format
	the default GstFormat for the new query
	 
Returns
	a new GstQuery. 

-----------------------------------------------------------------------------------------------------------------------------------

gboolean  gst_element_query (GstElement * element,GstQuery * query)


Performs a query on the given element.

For elements that don't implement a query handler, this function forwards the query to a random srcpad or to the peer of a random linked sinkpad of this element.

Parameters:
element –
	a GstElement to perform the query on.query ( [transfer: none] ) –the GstQuery.
Returns –
	TRUE if the query could be performed.

----------------------------------------------------------------------------------------------------------------------------------

guint  gst_query_get_n_buffering_ranges (GstQuery *query);


Retrieve the number of values currently stored in the buffered-ranges array of the query's structure.

Parameters:
query
	a GST_QUERY_BUFFERING type query GstQuery
	 
Returns
	the range array size as a guint.

------------------------------------------------------------------------------------------------------------------------------------

gboolean  gst_query_parse_nth_buffering_range (GstQuery *query,guint index,gint64 *start,gint64 *stop);


Parse an available query and get the start and stop values stored at the index of the buffered ranges array.

Parameters:
query
	a GST_QUERY_BUFFERING type query GstQuery
	 
index
	position in the buffered-ranges array to read	 

start
	the start position to set, or NULL.
	[out][allow-none]
stop
	the stop position to set, or NULL.
	[out][allow-none]
Returns
	a gboolean indicating if the parsing succeeded.


-----------------------------------------------------------------------------------------------------------------------


gboolean  gst_element_query_duration (GstElement * element,GstFormat format,gint64 * duration)


Queries an element (usually top-level pipeline or playbin element) for the total stream duration in nanoseconds. This query will only work once the pipeline is prerolled (i.e. reached PAUSED or PLAYING state). The application will receive an ASYNC_DONE message on the pipeline bus when that is the case.

If the duration changes for some reason, you will get a DURATION_CHANGED message on the pipeline bus, in which case you should re-query the duration using this function.


Parameters:
element –
	a GstElement to invoke the duration query on.
format –
	the GstFormat requested
duration ( [out] [allow-none] ) –
	A location in which to store the total duration, or NULL.
Returns –
	TRUE if the query could be performed.
--------------------------------------------------------------------------------------------------------------------------


gboolean   gst_element_query_position (GstElement * element,GstFormat format,gint64 * cur)


Queries an element (usually top-level pipeline or playbin element) for the stream position in nanoseconds. This will be a value between 0 and the stream duration (if the stream duration is known). This query will usually only work once the pipeline is prerolled (i.e. reached PAUSED or PLAYING state). The application will receive an ASYNC_DONE message on the pipeline bus when that is the case.

If one repeatedly calls this function one can also create a query and reuse it in gst_element_query.

Parameters:
element –
	a GstElement to invoke the position query on.
format –	the GstFormat requested
cur ( [out] [allow-none] ) –
	a location in which to store the current position, or NULL.
Returns –
	TRUE if the query could be performed.
---------------------------------------------------------------------------------------------------------------------




































