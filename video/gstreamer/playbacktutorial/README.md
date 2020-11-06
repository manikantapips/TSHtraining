command to run playback turoial-1
	gcc playback-tutorial-1.c -o playback-tutorial-1 `pkg-config --cflags --libs gstreamer-1.0`
     
     
Command to Run playback tutorial-2
	gcc playback-tutorial-2.c -o playback-tutorial-2 `pkg-config --cflags --libs gstreamer-1.0`
	
	
	
	
	
	
	
	
	
	
	
	
	
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


